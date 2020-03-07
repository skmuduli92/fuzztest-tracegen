mkdir build
cd build

# debug build
cmake ..

# release build
cmake .. -DCMAKE_BUILD_TYPE=release
