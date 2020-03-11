

**Build instructions**

* Installing dependencies

  ```bash
  sudo apt-get install googletest
  cd /usr/src/googletest
  sudo cmake .
  sudo make
  sudo make install
  ```

- Debug build [ *default* ]

  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```

- Release build

  ```bash
  mkdir build
  cd build
  cmake .. -DCMAKE_BUILD_TYPE=Release
  make
  ```

- Running test in build directory

  ```bash
  make test
  ```

**Inheritance diagram**

<img src="./doc/inherit_graph_0.png" />
