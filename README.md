# EVOCTL

Linux equivalent of the Audient EVO Mixer for their EVO 8 audio interface.

The application allows the user to control the levels for low-latency monitoring of the hardware and software inputs.

The goal of the project is to be able to control all the parameters which are not available on the interface itself - not to make a complete clone of the Audient UI.

## Project status

Only the basic GUI has been built - no actual USB communication has been implemented yet. References

## Screenshots

N/A.

## Download

N/A.

## Building

The following commands are used to build the project:

    git clone http://github.com/soerenbnoergaard/evoctl
    git submodule init
    git submodule update
    make

The output will be an executable, `evoctl` in the `src/` directory.

## References

Other people have also been looking into controlling Audient interfaces from Linux:

- [audient-evo-linux-tools](https://github.com/vijay-prema/audient-evo-linux-tools)
- [mymixer](https://github.com/r00tman/mymixer)
