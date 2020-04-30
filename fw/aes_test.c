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

#define GOOD_ID 0x12

void quit() {
  P0 = P1 = P2 = P3 = 0xDE;
  P0 = P1 = P2 = P3 = 0xAD;
  P0 = P1 = P2 = P3 = 0x00;
  while (1)
    ;
}

__xdata __at(0xFF00) unsigned char aes_reg_start;
__xdata __at(0xFF01) unsigned char aes_reg_state;
__xdata __at(0xFF02) unsigned int aes_reg_addr;
__xdata __at(0xFF04) unsigned int aes_reg_oplen;
__xdata __at(0xFF10) unsigned char aes_reg_ctr[16];
__xdata __at(0xFF20) unsigned char aes_reg_key0[16];
__xdata __at(0xFF30) unsigned char aes_reg_key1[16];
__xdata __at(0xE000) unsigned char data[1024];
__xdata __at(0xE400) unsigned char vdata[1024];

__xdata __at(0xFF80) unsigned char pt_wren[32];
__xdata __at(0xFFA0) unsigned char pt_rden[32];

__xdata __at(0xEFFC) unsigned int debug_reg_addr;
__xdata __at(0xEFFE) unsigned int debug_reg_data;

/*---------------------------------------------------------------------------*/

void main() {

  int i;
  /* int good = 1; */

  // test writing to XRAM. (working fine)
  /* for (i = 0; i < aes_reg_oplen; i++) { */
  /*   /\* data[i] = i; *\/ */
  /*   P0 = data[i]; */
  /*   P1 = 0x11; */
  /* } */

  for (i = 0; i < aes_reg_oplen; ++i) {
    data[i] = vdata[i];
  }

  /* P1 = 0x00; */

  // setup address, length, counter and key.
  aes_reg_addr = 0xE000;

  /* for (i = 0; i < 16; i++) { */
  /*   aes_reg_ctr[i] = i * i * i;  // being updated at by verilator */
  /*                                // so not doing initialization here */
  /*   P0 = aes_reg_key0[i]; */
  /*   P1 = aes_reg_ctr[i]; */
  /* } */

  // now start encryption.
  P1 = 0xAA;
  aes_reg_start = 1;
  // now wait for encryption to complete.
  while (aes_reg_state != 0)
    ;

  // read encrypted data and dump it to P0.
  /* for (i = 0; i < aes_reg_oplen; i++) { */
  /*   P0 = data[i]; */
  /* } */

  // let us decrypt now.
  aes_reg_start = 1;
  while (aes_reg_state != 0) {
    __asm;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    nop;
    __endasm;
  }

  /* for (i = 0; i < aes_reg_oplen; i++) { */
  /*   if (data[i] != vdata[i]) { */
  /*     good = 2; */
  /*     break; */
  /*   } */
  /* } */

  /* P0 = good; */
  /* debug_reg_addr = GOOD_ID; */
  /* debug_reg_data = good; */
  // finish.
  quit();
}
