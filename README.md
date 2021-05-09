# evoctl

Linux equivalent of the Audient EVO Mixer for their EVO audio interfaces.

The application allows the user to control the levels for low-latency monitoring of the hardware and software inputs.

The goal of the project is to be able to control all the parameters which are not available on the interface itself - not to make a complete clone of the Audient UI.

## Screenshot

![evoctl screenshot](https://raw.githubusercontent.com/soerenbnoergaard/evoctl/main/doc/screenshot1.png)

## Usage

This program detaches the kenel driver and configures the audio interface. The recommended workflow is therefore:

1. Make sure Jack is stopped
2. Start `evoctl` 
3. Configure the low-latency routing for your session
4. Exit `evoctl`
5. Start Jack

At the moment, it is not possible to re-configure the low-latency routing while Jack is running.

## System setup

To use the program without sudo, create the file `/etc/udev/rules.d/70-audient.evo.rules` with the following content:

    SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0006", MODE="0666"
    SUBSYSTEM=="usb", ATTR{idVendor}=="2708", ATTR{idProduct}=="0007", MODE="0666"

## Download

No binary releases are available so the program must be built fron source - see below.

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

## Project status

Completed:
- USB descriptor details obtained with lsusb (see `/doc/lsusb_vvv_audient_evo_8.txt`).
- USB control messages sniffed with Wireshark and included in the file `/doc/usb_control_messages.ods` (also includes messages no implemented in the program).
- Basic GUI implemented as a transfer matrix allowing the user to set the volume from any source to any destination.
- USB control implemented and working.

Limitations/still missing:
- It is only possible to use this program before Jack is started, as the detaching and reattaching of kernel driver messes up Jack. Please let me know if you know a way around this!
- No parameters are read back from the device, so the settings are reset at startup.

