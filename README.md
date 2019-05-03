# regex

This project demonstrates how to use partial evaluation in conjunction with Just-In-Time compilation.
The presented program takes a regular expression and generates efficient code to match this regular expression against a string.

## Building

In order to build this program, you must install AnyDSL, and enable Just-In-Time compilation in the runtime.
Once this is done, you can build this project by typing from the root directory:

    mkdir build
    cd build
    cmake .. -DAnyDSL_runtime_DIR=<path to AnyDSL runtime config>
    make -j

Usually, the path to the AnyDSL runtime config is in `<AnyDSL root dir>/runtime/build/share/anydsl/cmake`.

## Running

To run the program from the `build` directory, type:

    src/regex <regular expression> <string to match>

