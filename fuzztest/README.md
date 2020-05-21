# FuzzTest

1. **Build Verilator**
   ```bash
   cd $PROJECT_ROOT/verilator
   export VERILATOR_ROOT=$PWD
   autoconf && ./configure && make -j4
   ```

2. **Building and running examples**

    ```bash
    cd $PROJECT_ROOT/fuzztest
    mkdir build && cd build && make aes_test -j4
    cd bin
    ```
    *You must change directory to bin directory while executing any example else some of the relative paths will not get resolved properly*
