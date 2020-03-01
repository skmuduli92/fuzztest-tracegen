PROFILE:=0
DEBUG?=0
CC=gcc
CXX:=g++
LD=g++
AR=ar
RANLIB=ranlib
STATIC?=0
CPLEX?=0

ifeq ($(PROFILE), 1)
    PGFLAGS:=-pg
else
    PGFLAGS:=
endif

ifeq ($(DEBUG), 1)
    DBGFLAGS:=-g
    OPTFLAGS:=
else
    DBGFLAGS:=
    OPTFLAGS:=-O3
endif

INCLUDE:=

DEFINES:=

CXXFLAGS:=-c -Wall -Werror -Wno-error=deprecated -fopenmp -std=c++17 \
	${INCLUDE} ${DEFINES} ${DBGFLAGS} ${OPTFLAGS} ${PGFLAGS} \
	-Wno-strict-overflow

#Find all the C++ files in the current directory.
SOURCES:=$(shell find . -name "*.cpp" | grep -v mcqd.cpp)
#These are the dependency files, which make will clean up after it creates them
DEPFILES:=$(patsubst %.cpp,%.d,$(SOURCES))
#Objects
OBJECTS:=$(patsubst %.cpp,%.o,$(SOURCES))

libprop.a: $(OBJECTS)
	$(AR) rc $@ $<
	$(RANLIB) $@

# This is the rule for creating the dependency files
%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM $< > $@

# This include statement pulls in the commands to build the .o files.
include $(subst .cpp,.d,$(SOURCES))

.PHONY: clean

clean:
	rm *.a *.o
