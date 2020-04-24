#include <reg51.h>

/*
 * Copyright (c) 1999-2001 Tony Givargis.  Permission to copy is granted
 * provided that this header remains intact.  This software is provided
 * with no warranties.
 *
 * Version : 2.9
 */

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/

__xdata __at(0xFF80) unsigned char pt_wren[32];
__xdata __at(0xFFA0) unsigned char pt_rden[32];

void quit() {
  P0 = P1 = P2 = P3 = 0xDE;
  P0 = P1 = P2 = P3 = 0xAD;
  P0 = P1 = P2 = P3 = 0x00;
  while (1)
    ;
}

__xdata __at(0xF9F0) unsigned char memwr_reg_start;
__xdata __at(0xF9F1) unsigned char memwr_reg_state;
__xdata __at(0xF9F2) unsigned int memwr_reg_rd_addr;
__xdata __at(0xF9F4) unsigned int memwr_reg_wr_addr;
__xdata __at(0xF9F6) unsigned int memwr_reg_len;

__xdata __at(0x0000) unsigned char datasrc[64];
__xdata __at(0x1000) unsigned char datadst[64];

/*---------------------------------------------------------------------------*/

void main() {

  int i;
  int good = 1;

  // setup address, length, counter and key.
  memwr_reg_rd_addr = (unsigned int)&datasrc;
  memwr_reg_wr_addr = (unsigned int)&datadst;
  memwr_reg_len = 64;

  // start copying
  // set this inside the

  P1 = 0x0F;

  for (i = 0; i < 64; ++i) {
    datasrc[i] = i;
    datadst[i] = 64 - i;
  }

  P1 = 0xAA;

  // memwr_reg_start = 1;
  // now wait for copying to complete.
  while (memwr_reg_state != 0) {
    P1 = 0XBB;
  }

  P1 = 0xCC;

  for (i = 0; i < 64; ++i) {
    if (datadst[i] != (unsigned char)i)
      P0 = i;
    else
      P0 = 0x1A;
  }

  quit();
}
