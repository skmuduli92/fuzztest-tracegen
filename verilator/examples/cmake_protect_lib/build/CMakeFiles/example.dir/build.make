# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build

# Include any dependencies generated for this target.
include CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example.dir/flags.make

CMakeFiles/example.dir/Vtop.dir/Vtop.cpp: /home/sujit/Tools/DeltaSigmaSoC/verilator/bin/verilator_bin
CMakeFiles/example.dir/Vtop.dir/Vtop.cpp: /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/top.v
CMakeFiles/example.dir/Vtop.dir/Vtop.cpp: /home/sujit/Tools/DeltaSigmaSoC/verilator/bin/verilator_bin
CMakeFiles/example.dir/Vtop.dir/Vtop.cpp: verilated_secret/verilated_secret.sv
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CMakeFiles/example.dir/Vtop.dir/Vtop.cpp, CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp, CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp, CMakeFiles/example.dir/Vtop.dir/Vtop.h, CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.h, CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.h, CMakeFiles/example.dir/Vtop.dir/Vtop.cmake"
	cd /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib && /home/sujit/Tools/DeltaSigmaSoC/verilator/bin/verilator_bin --compiler gcc --prefix Vtop --Mdir /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir --make cmake --cc -I/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret ../make_protect_lib/top.v

CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp

CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp

CMakeFiles/example.dir/Vtop.dir/Vtop.h: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop.h

CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.h: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.h

CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.h: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.h

CMakeFiles/example.dir/Vtop.dir/Vtop.cmake: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/example.dir/Vtop.dir/Vtop.cmake

CMakeFiles/example.dir/Vtop.dir/Vtop_copy.cmake: CMakeFiles/example.dir/Vtop.dir/Vtop.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CMakeFiles/example.dir/Vtop.dir/Vtop_copy.cmake"
	/usr/bin/cmake -E copy_if_different /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop.cmake /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop_copy.cmake

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o: /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp > CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.i

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.s

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.requires

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.provides: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.provides

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.provides.build: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o


CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp > CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.i

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.s

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.requires

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.provides: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.provides

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.provides.build: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o


CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o: CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp > CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.i

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.s

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.requires

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.provides: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.provides

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.provides.build: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o


CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o: CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp > CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.i

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp -o CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.s

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.requires

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.provides: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.provides

CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.provides.build: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o


CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o: /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp > CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.i

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.s

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.requires

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.provides: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.provides

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.provides.build: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o


CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o: /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o -c /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp > CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.i

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp -o CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.s

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.requires

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.provides: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.provides

CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.provides.build: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o


# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o" \
"CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o" \
"CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o" \
"CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o" \
"CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o" \
"CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

example: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o
example: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o
example: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o
example: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o
example: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o
example: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o
example: CMakeFiles/example.dir/build.make
example: libverilated_secret.a
example: CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example.dir/build: example

.PHONY : CMakeFiles/example.dir/build

CMakeFiles/example.dir/requires: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/make_protect_lib/sim_main.cpp.o.requires
CMakeFiles/example.dir/requires: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp.o.requires
CMakeFiles/example.dir/requires: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp.o.requires
CMakeFiles/example.dir/requires: CMakeFiles/example.dir/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp.o.requires
CMakeFiles/example.dir/requires: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated.cpp.o.requires
CMakeFiles/example.dir/requires: CMakeFiles/example.dir/home/sujit/Tools/DeltaSigmaSoC/verilator/include/verilated_dpi.cpp.o.requires

.PHONY : CMakeFiles/example.dir/requires

CMakeFiles/example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example.dir/clean

CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop.cpp
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.cpp
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop.h
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop__Dpi.h
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.h
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop.cmake
CMakeFiles/example.dir/depend: CMakeFiles/example.dir/Vtop.dir/Vtop_copy.cmake
	cd /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example.dir/depend

