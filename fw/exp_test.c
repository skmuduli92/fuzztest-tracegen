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

void quit() {
  P0 = P1 = P2 = P3 = 0xDE;
  P0 = P1 = P2 = P3 = 0xAD;
  P0 = P1 = P2 = P3 = 0x00;
  while (1)
    ;
}

#define N 256
// __xdata __at(0xFD02) unsigned int exp_reg_addr;

__xdata __at(0xE000) unsigned char data[256];
__xdata __at(0xE100) unsigned char comp[256];

__xdata __at(0xFD00) unsigned char exp_reg_start_op;
__xdata __at(0xFD01) unsigned char exp_reg_state;
__xdata __at(0xFD02) unsigned int exp_reg_opaddr;
__xdata __at(0xFC00) unsigned char exp_reg_n[N];
__xdata __at(0xFB00) unsigned char exp_reg_exp[N];
__xdata __at(0xFA00) unsigned char exp_reg_m[N];

__xdata __at(0xF000) unsigned char vn[256];
__xdata __at(0xF100) unsigned char vexp[256];
__xdata __at(0xF200) unsigned char vm[256];
__xdata __at(0xF300) unsigned char vdata[256];

/*---------------------------------------------------------------------------*/

void main() {
  int i;
  int good = 1;

  // setup address, m, e, n
  exp_reg_opaddr = 0xE000;

  P0 = 0xaa;

  for (i = 0; i < 256; i++) {
    exp_reg_m[i] = vm[i];
    exp_reg_n[i] = vn[i];
    exp_reg_exp[i] = vexp[i];
    comp[i] = vdata[i];
    data[i] = vm[i];

    P0 = exp_reg_m[i];
    P1 = exp_reg_n[i];
    P2 = exp_reg_exp[i];
  }

  // now start encryption.
  exp_reg_start_op = 1;  // start encryption
  while (exp_reg_state != 0) {
    /* P0 = exp_reg_state; */
  }  // wait for encryption to finish

  P0 = 0xDD;
  // read encrypted data and dump it to P0.
  for (i = 0; i < 256; i++) {
    P0 = data[i];
    P1 = comp[i];
    if (data[i] != *(comp + i)) {
      good = 0;
      break;
    }
  }
  P0 = good;
  // finish.
  quit();
}
