UUID Generator

Takes 5 arguments and outputs into UUID version 4 format, 128 bit Hexidecimal string:
XXXXXXXX-XXXX-4XXX-XXXX-XXXXXXXXXXXX

Input assumes string inputs in the range 0 < input <= 0xFFFF|0xFFFFFFFF|0xFFFFFFFFFFFF, 
depending on argument.

Minimal guarding on arguments, assuming internal usage only.
For public interfaces, the arguments would need more guarding/formatting.

I chose the UUID version 4 variant, which is usually done with random number generators.
This seemed to fit best with the instructions to output UUID for a given set of inputs.

CMake for Linux/MacOS with Make Directions:

The generator name for CMake is Unix Makefiles. Assuming the current task is bob and
we're in the task folder:

touch bob.{h,cpp}
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
