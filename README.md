# SHEnvGen

An ASR envelope generator that behaves like the envelope generator in the
Moog Subharmonicon.

When a gate signal is received by the envelope generator, it will begin its
attack phase and rises to its maximum level. The envelope generator remains in
its attack phase even if the original gate is released or if new gates are
received. Once it reaches its maximum level, it sustains until the gate signal
is released. The envelope generator will then begin its release phase and fall
to its minimum level unless a new gate signal is received.

### Requirements

- CMake >= 3.5
- SuperCollider source code

### Building

Clone the project:

    git clone https://github.com/midouest/SHEnvGen
    cd SHEnvGen
    mkdir build
    cd build

Then, use CMake to configure and build it:

    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build . --config Release
    cmake --build . --config Release --target install

You may want to manually specify the install location in the first step to point it at your
SuperCollider extensions directory: add the option `-DCMAKE_INSTALL_PREFIX=/path/to/extensions`.

It's expected that the SuperCollider repo is cloned at `../supercollider` relative to this repo. If
it's not: add the option `-DSC_PATH=/path/to/sc/source`.
