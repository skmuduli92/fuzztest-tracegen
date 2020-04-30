#include <fstream>
#include <iostream>

int main(void) {

  std::ofstream fs("in1.bin", std::ios::binary | std::ios::out);

  unsigned data = 0;

  for (size_t id = 0; id < 256; ++id) fs.write((char *)&data, sizeof(data));

  fs.close();
  return 0;
}
