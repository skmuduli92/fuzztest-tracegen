# fuzztest

Note: make sure you have built the following before running make in this directory.

1. Verilator

   ```bash
   cd verilator
   export VERILATOR_ROOT=$PWD
   autoconf
   ./configure
   make -j8
   ```

   

2. libprop

   ```bash
   cd libprop
   mkdir build && cd build
   cmake .. && make -j4
   ```

   

#### Generating Traces for HyperMiner experiment

1. **Kernel configuration to run AFL**

   - run the given script `kernel-config.sh` 

2. **Getting interesting inputs from custom coverage metric**

   - ###### <u>step - 1</u>: Build an experiment say `aes_test`

     - compile `aes_test` firmware by running `sh genaesfw.sh `

     - `rm -f *.o && make aes_test`

     - Run afl-fuzzer for `aes_test` binary with the given seed input, 

       `afl-fuzz -t 10000 -i afl-in/aes_test/ -o aes-out ./aes_test`

       Let the fuzzer to run for sometime (until it has discovered sufficient no. of new paths). This will create some interesting input and dump them inside `aes-out/queue`

       

   - ###### <u>step - 2:</u> Simulating interesting inputs

     - `rm -f  *.o && SIMULATE_TRACES=1 make aes_test` 

     - Then simulate the interesting inputs generated in **step - 1**, `./aes_test ./aes-out/queue/`

       This will create a new directory `trace_output` and dump the traces which is going to be used for property mining.
   
   