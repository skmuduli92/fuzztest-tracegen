# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vsecret_impl.mk

default: libverilated_secret

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /home/sujit/Tools/DeltaSigmaSoC/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vsecret_impl
# Module prefix (from --prefix)
VM_MODPREFIX = Vsecret_impl
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-fPIC \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \


### Default rules...
# Include list of all generated classes
include Vsecret_impl_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Library rules... (from --protect-lib)
# Using -fPIC objects for both static and dynamic libraries (which appears to work)
libverilated_secret.a: $(VK_OBJS) $(VK_GLOBAL_OBJS)
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o verilated_secret.o verilated_secret.cpp
	ar rc $@ $^ verilated_secret.o

libverilated_secret.so: $(VM_PREFIX)__ALL.a $(VK_GLOBAL_OBJS)
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -shared -o $@ verilated_secret.cpp $^

libverilated_secret: libverilated_secret.a libverilated_secret.so

# Verilated -*- Makefile -*-
