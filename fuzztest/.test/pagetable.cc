#include <fstream>
#include <iostream>

int main(void) {

  std::ofstream fs("in1.bin", std::ios::binary | std::ios::out);

  unsigned data = rand() % 3;
  fs.write((char *)&data, sizeof(data));

  data = rand() % 128;
  fs.write((char *)&data, sizeof(data));

  data = rand() % 4;
  fs.write((char *)&data, sizeof(data));

  fs.close();
  return 0;
}
