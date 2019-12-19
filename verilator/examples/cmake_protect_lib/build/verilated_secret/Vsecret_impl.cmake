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
set(Vsecret_impl_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vsecret_impl_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vsecret_impl_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vsecret_impl_COVERAGE 0)
# Threaded output mode?  0/1/N threads (from --threads)
set(Vsecret_impl_THREADS 0)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vsecret_impl_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --fst-trace)
set(Vsecret_impl_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vsecret_impl_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vsecret_impl_CLASSES_SLOW )
# Generated module classes, fast-path, compile with highest optimization
set(Vsecret_impl_CLASSES_FAST "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/Vsecret_impl.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vsecret_impl_SUPPORT_SLOW "/home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/Vsecret_impl_PSfoAy.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(Vsecret_impl_SUPPORT_FAST )
# All dependencies
set(Vsecret_impl_DEPS "../make_protect_lib/secret_impl.v" "/home/sujit/Tools/DeltaSigmaSoC/verilator/bin/verilator_bin")
# User .cpp files (from .cpp's on Verilator command line)
set(Vsecret_impl_USER_CLASSES )
