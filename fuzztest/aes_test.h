#ifndef __AES_TEST_H__
#define __AES_TEST_H__

#include <random>

uint8_t gen8bit() { return rand() % 128; }
uint16_t gen16bit() { return rand() % 65536; }

#define DATA_LOC 0xE000
#define AES_REG_START 0xFF00
#define AES_REG_LEN 0xFF04
#define DEBUG_REG_ADDR 0xEFFC

void randomize_aes() {

  // set the aes data block length
}

#endif
