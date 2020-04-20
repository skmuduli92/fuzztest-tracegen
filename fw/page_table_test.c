#include <reg51.h>

/*
 * Test for Page Table
 */

/*---------------------------------------------------------------------------*/

void quit() {
  P0 = P1 = P2 = P3 = 0xDE;
  P0 = P1 = P2 = P3 = 0xAD;
  P0 = P1 = P2 = P3 = 0x00;
  while (1)
    ;
}

/*---------------------------------------------------------------------------*/

void main() {
  __xdata __at(0xFF80) unsigned char pt_wren[32];
  __xdata __at(0xFFA0) unsigned char pt_rden[32];

  __xdata __at(0x0000) unsigned char xram_start_data[256];
  __xdata __at(0x0800) unsigned char xram_mid_data[256];
  __xdata __at(0x1000) unsigned char xram_end_data[256];

  /* __xdata __at(0xEFE6) unsigned int read_succeed; */
  /* __xdata __at(0xEFEA) unsigned int write_succeed; */

  __xdata __at(0xEFEE) unsigned int xram_segment;

  __xdata __at(0xEFF2) unsigned int rd_mode;
  __xdata __at(0xEFF6) unsigned int wr_mode;

  __xdata __at(0xEFFA) unsigned int debug_reg_addr;
  __xdata __at(0xEFFE) unsigned int debug_reg_data;

  // first disable writing to and reading from the page
  /* pt_wren[xram_segment] = wr_mode; */
  /* pt_rden[xram_segment] = rd_mode; */

  /* pt_wren[0] = 0x00; */
  /* pt_rden[0] = 0x01; */

  if (xram_segment == 0x00) {
    xram_start_data[debug_reg_addr] = debug_reg_data;
    P0 = xram_start_data[debug_reg_addr];
    P1 = 0x01;
  } else if (xram_segment == 0x01) {
    xram_mid_data[debug_reg_addr] = debug_reg_data;
    P0 = xram_mid_data[debug_reg_addr];
    P1 = 0x02;
  } else {
    xram_end_data[debug_reg_addr] = debug_reg_data;
    P0 = xram_end_data[debug_reg_addr];
    P1 = 0x03;
  }

  quit();
}
