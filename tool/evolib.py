# USB control message prototyping based on code from vijay-prema

# udev rule (/etc/udev/rules.d/70-audient.evo.rules):
#
#     SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0006", MODE="0666"
#     SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0007", MODE="0666"

import struct
import usb.core
import usb.util

class AudientEvo(object):
    def __init__(self, idVendor, idProduct):
        self.dev = None
        self.reattach = False

        # find our device
        self.dev = usb.core.find(idVendor=idVendor, idProduct=idProduct)

        # was it found?
        if self.dev is None:
            raise ValueError('Device not found')

        if self.dev.is_kernel_driver_active(0):
            self.reattach = True
            self.dev.detach_kernel_driver(0)

        usb.util.claim_interface(self.dev, 0)
        self.dev.reset()

        # set the active configuration. With no arguments, the first
        # configuration will be the active one
        self.dev.set_configuration()

    def __del__(self):
        if self.dev is not None:
            self.close()

    def close(self):
        # This is needed to release interface, otherwise attach_kernel_driver fails 
        # due to "Resource busy"
        usb.util.dispose_resources(self.dev)

        # Return control back to kernel driver
        # It may raise USBError if there's e.g. no kernel driver loaded at all
        if self.reattach:
            self.dev.attach_kernel_driver(0)

        self.dev = None

    def write(self, wValue, wIndex, data):
        # SEND CONTROL DATA
        # Params are: bmRequestType, bmRequest, wValue, wIndex, dataFragment
        # Copy these from the Wireshark recording
        # Assert return value is length of bytes sent (length of dataFragment)
        data = struct.pack("B"*len(data), *data)

        assert self.dev.ctrl_transfer(0x21, 1, wValue, wIndex, data) == len(data)

    def set_volume_out12_dBFS(self, volume):
        assert volume <= 0
        volume = volume + 255
        self.write(0x0000, 0x3b00, [0x00, volume, 0xff, 0xff])

class AudientEvo4(AudientEvo):
    def __init__(self):
        super().__init__(idVendor=0x2708, idProduct=0x0006)

class AudientEvo8(AudientEvo):
    def __init__(self):
        super().__init__(idVendor=0x2708, idProduct=0x0007)

def main():
    dev = AudientEvo8()

    # import pdb; pdb.set_trace()

    # Headphone Volume. 2nd byte in data is volume level from 0x00 to 0xff
    dev.write(wValue=0x0000, wIndex=0x3b00, data=[0x00, 0xf0, 0xff, 0xff])

    # 48V (channel 1). First byte is 0x01 or 0x00 for on or off
    # dev.write(wValue=0x0000, wIndex=0x3a00, data=[0x01, 0x00, 0x00, 0x00])

    # Mic (channel 1) Volume. 2nd byte in data is volume level from 0x00 to 0x31
    # dev.write(wValue=0x0100, wIndex=0x3a00, data=[0x00, 0x1f, 0x00, 0x00])

    dev.close()

if __name__ == "__main__":
    main()
