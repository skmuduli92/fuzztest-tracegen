# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/home/sujit/Tools/DeltaSigmaSoC/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vtop_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vtop_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vtop_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vtop_COVERAGE 1)
# Threaded output mode?  0/1/N threads (from --threads)
set(Vtop_THREADS 0)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vtop_TRACE_VCD 1)
# FST Tracing output mode? 0/1 (from --fst-trace)
set(Vtop_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vtop_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_cov.cpp" "${VERILATOR_ROOT}/include/verilated_vcd_c.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vtop_CLASSES_SLOW )
# Generated module classes, fast-path, compile with highest optimization
set(Vtop_CLASSES_FAST "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_tracing_c/build/CMakeFiles/example.dir/Vtop.dir/Vtop.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vtop_SUPPORT_SLOW "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_tracing_c/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Syms.cpp" "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_tracing_c/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Trace__Slow.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(Vtop_SUPPORT_FAST "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_tracing_c/build/CMakeFiles/example.dir/Vtop.dir/Vtop__Trace.cpp")
# All dependencies
set(Vtop_DEPS "../make_tracing_c/../make_tracing_c/top.v" "../make_tracing_c/input.vc" "../make_tracing_c/sub.v" "/home/sujit/Tools/DeltaSigmaSoC/verilator/bin/verilator_bin")
# User .cpp files (from .cpp's on Verilator command line)
set(Vtop_USER_CLASSES )
