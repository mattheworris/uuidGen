Linux/MacOS with Make Directions

The generator name for CMake is Unix Makefiles. Assuming the current task is bob and
we're in the task folder:

touch bob.{h,cpp}
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make