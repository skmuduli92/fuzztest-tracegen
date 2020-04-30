#include <fstream>
#include <iostream>
#include <limits>

int main(void) {

  std::ofstream fs("in1.bin", std::ios::binary | std::ios::out);

  for (size_t i = 0; i < 32; i++) {

    // uint8_t data = rand() % std::numeric_limits<uint8_t>::max();
    uint8_t data = rand() % std::numeric_limits<uint8_t>::max();
    uint16_t offset = rand() % std::numeric_limits<uint16_t>::max();

    fs.write((char *) &data, sizeof(data));
    fs.write((char *) &offset, sizeof(offset));
}

  fs.close();
  return 0;
}
