

**Build instructions**

* Installing dependencies

  ```bash
  sudo ./setup.sh
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

[(complete class diagram)](https://github.com/tgourav/fuzztest/blob/master/libprop/doc/class_hyper_p_l_t_l_1_1_formula__inherit__graph.png)
