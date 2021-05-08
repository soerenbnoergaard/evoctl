# evoctl

Linux equivalent of the Audient EVO Mixer for their EVO 8 audio interface.

The application allows the user to control the levels for low-latency monitoring of the hardware and software inputs.

The goal of the project is to be able to control all the parameters which are not available on the interface itself - not to make a complete clone of the Audient UI.

## Status

Completed:
- Control messages sniffed with Wireshark and included in the file `/doc/usb_control_messages.ods` (also includes messages no implemented in the program).
- Basic GUI implemented as a transfer matrix allowing the user to set the volume from any source to any destination.
- USB control implemented and working.

Still missing:
- As this program detaches the kernel driver, it is not possibly to use alongside Jack yet. I am hoping to fix this major limitation as soon as possible.

## Screenshot

![evoctl screenshot](https://raw.githubusercontent.com/soerenbnoergaard/evoctl/main/doc/screenshot1.png)

## Download

No binary releases are available so the program must be built fron source - see below.

## Setup

To use the program without sudo, create the file `/etc/udev/rules.d/70-audient.evo.rules` with the following content:

    SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0006", MODE="0666"
    SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0007", MODE="0666"

## Build

The following commands are used to build the project:

    git clone http://github.com/soerenbnoergaard/evoctl
    cd evoctl
    git submodule init
    git submodule update
    make

The output will be an executable, `evoctl` in the `src/` directory.

## References

Other people have also been looking into controlling Audient interfaces from Linux:

- [audient-evo-linux-tools](https://github.com/vijay-prema/audient-evo-linux-tools)
- [mymixer](https://github.com/r00tman/mymixer)

Both of these have been very helpful in the development of this tool - thanks a lot!

Libraries:

- [libusb](https://libusb.info/)
- [FLTK](https://www.fltk.org/)
