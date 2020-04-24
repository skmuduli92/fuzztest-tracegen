#include <8051.h>

/*
 * Copyright (c) 1999-2001 Tony Givargis.  Permission to copy is granted
 * provided that this header remains intact.  This software is provided
 * with no warranties.
 *
 * Version : 2.9
 */

/*---------------------------------------------------------------------------*/

#define N 64

__xdata __at(0xFF80) unsigned char pt_wren[32];
__xdata __at(0xFFA0) unsigned char pt_rden[32];

__xdata __at(0xF9F0) unsigned char memwr_reg_start;
__xdata __at(0xF9F1) unsigned char memwr_reg_state;
__xdata __at(0xF9F2) unsigned int memwr_reg_rd_addr;
__xdata __at(0xF9F4) unsigned int memwr_reg_wr_addr;
__xdata __at(0xF9F6) unsigned int memwr_reg_len;

__xdata __at(0x5000) unsigned char boot[0x2000];

__xdata __at(0xFE00) unsigned char sha_reg_start;
__xdata __at(0xFE01) unsigned char sha_reg_state;
__xdata __at(0xFE02) unsigned int sha_reg_rd_addr;
__xdata __at(0xFE04) unsigned int sha_reg_wr_addr;
__xdata __at(0xFE06) unsigned int sha_reg_len;

__xdata __at(0xC000) unsigned char sha_in[0x2080];
__xdata __at(0xE080) unsigned char sha_out[20];
__xdata __at(0xE100) unsigned char rsa_out[N];

__xdata __at(0xFD00) unsigned char exp_reg_start;
__xdata __at(0xFD01) unsigned char exp_reg_state;
__xdata __at(0xFD02) unsigned int exp_reg_opaddr;
__xdata __at(0xFC00) unsigned char exp_reg_n[N];
__xdata __at(0xFB00) unsigned char exp_reg_exp[N];
__xdata __at(0xFA00) unsigned char exp_reg_m[N];

// state of PRG for R and G in OAEP
__xdata __at(0xFD10) unsigned char rprg[20];
__xdata __at(0xFD30) unsigned char gprg[20];

struct image {
  unsigned char sig[N];  // signature of header (encryption of the message)
  unsigned char exp[N];
  unsigned char mod[N];  // (exp, mod) is the public key
  unsigned char msg[N];
};

// encrypt msg with (exp, mod) and compare it with signature sig

unsigned char* decrypted;
unsigned char* hash;
unsigned char* data;

// set up RSA
void RSAinit();
// encrypt msg and put result in exp_reg_opaddr
void encrypt();  //(unsigned char* msg, unsigned int len);
// decrypt msg and put result in exp_reg_opaddr->m
void decrypt(unsigned char* msg);
// sign message, put signature in exp_reg_opaddr
// void sign(unsigned char* message, unsigned int len);
// verify that msg matches sign, ret 1 if match, 0 if not
unsigned char verifySignature(unsigned char* msg, unsigned int len, unsigned char* sign);

// void pad(unsigned int len);
// int unpad();
void sha1(unsigned char* m, unsigned int len);
void HMAC(unsigned char* key, unsigned int klen, unsigned char* message, unsigned int mlen);
void PRGinit(unsigned char* seed, unsigned int slen, unsigned char* state);
void PRG(unsigned char* prg);
void OAEP();
int removeOAEP();

// copy length bytes from data in XRAM to startaddr
void load(unsigned char* data, unsigned int length, unsigned int startaddr,
          unsigned char skipread);

// set up data transfer
void load(unsigned char* data, unsigned int length, unsigned int startaddr,
          unsigned char skipread) {
  memwr_reg_rd_addr = (unsigned int)data;
  memwr_reg_wr_addr = startaddr;
  memwr_reg_len = length;
  memwr_reg_start = (unsigned char)(skipread << 1 | 1);

  // wait for load to finish
  while (memwr_reg_state != 0)
    ;
}

void RSAinit() {
  // decrypted = (__xdata unsigned char*)exp_reg_opaddr;
  /* hash = (__xdata unsigned char*)sha_reg_wr_addr; */
  /* data = (__xdata unsigned char*)sha_reg_rd_addr; */
}

/* void pad(unsigned int len) { */
/*   unsigned int i; */

/*   exp_reg_m.m[len] = 1; */
/*   for (i = len + 1; i < sizeof(exp_reg_m.m); i++) exp_reg_m.m[i] = 0; */
/* } */

// returns length of message
/* int unpad() { */
/*   int len; */

/*   for (len = sizeof(exp_reg_m.m) - 1; len >= 0; len--) { */
/*     if (decrypted->m[len] == 1) */
/*       break; */
/*     else if (decrypted->m[len] != 0) */
/*       return -1; */
/*   } */
/*   return len; */
/* } */

// set up message for sha
void sha1(unsigned char* m, unsigned int len) {
  unsigned int i;
  unsigned int mlen;

  // setup data
  mlen = ((len + 4) & 0xFFC0) + 64;  // round len+5 up to multiple of 64
  sha_reg_len = mlen;

  if ((unsigned int)m != sha_reg_rd_addr)  // don't copy if already in right address
    load(m, len, sha_reg_rd_addr, 0);      // copy m

  // add 100.. padding
  data[len] = 0x80;

  for (i = len + 1; i < mlen; i++) data[i] = 0;

  // insert length in bits
  data[mlen - 1] = (len << 3) & 0xFF;
  data[mlen - 2] = (len >> 5) & 0xFF;
  data[mlen - 3] = (len >> 13) & 0xFF;

  // encrypt with sha1
  sha_reg_start = 1;
  while (sha_reg_state != 0)
    ;
}

// encrypt message, len bytes
void encrypt() {
  /* unsigned int i; */

  /* if (msg != exp_reg_m) */
  /*   for (i = 0; i < len; i++) { */
  /*     P0 = 0xa3; */
  /*     exp_reg_m[i] = msg[i]; */
  /*   } */

  P0 = 0xa3;

  exp_reg_start = 1;  // start encryption
  while (exp_reg_state != 0)
    ;  // wait for encryption to finish
}

// decrypt msg, puts decrypted text in exp_reg_opaddr
// returns length of decrypted message
void decrypt(unsigned char* msg) {
  unsigned int i;

  if (msg != (unsigned char*)exp_reg_m)
    for (i = 0; i < N; i++) ((unsigned char*)exp_reg_m)[i] = msg[i];
  // decrypt
  exp_reg_start = 1;
  while (exp_reg_state != 0)
    ;

  // check pad byte
  // if (decrypted->padbyte != 1) return 0;

  //  return unpad();
}

int good = 1;

void quit() {
  P0 = P1 = P2 = P3 = 0xDE;
  P0 = P1 = P2 = P3 = 0xAD;
  P0 = P1 = P2 = P3 = 0x00;
  while (1)
    ;
}

void main() {
  unsigned int i;
  unsigned int size = N;
  // unsigned int num;
  /* struct image* im; */

  // enable reading and writing everywhere for now
  for (i = 0; i < 32; i++) {
    pt_wren[i] = 0xFF;
    pt_rden[i] = 0xFF;
  }

  // load some data
  // TODO : perform read write once rsa works
  // load(0, 0x2000, (unsigned int)&boot, 1);
  /* im = (struct image*)boot; */
  // num = im->num;  // number of modules
  // sizeof image struct includes extra signature and first module
  /* size = N; */

  // set SHA read and write addresses
  /* sha_reg_rd_addr = (unsigned int)&sha_in; */

  /* sha_reg_wr_addr = (unsigned int)&sha_out; */

  // set up RSA
  exp_reg_opaddr = (unsigned int)&rsa_out;  // set up address to write to
  decrypted = (__xdata unsigned char*)exp_reg_opaddr;
  // RSAinit();

  // set signature modulus [set up in verilator sim
  /* for (i = 0; i < N; i++) exp_reg_n[i] = im->mod[i]; */

  // set signature key [set in verilator sim]
  /* for (i = 0; i < N; i++) exp_reg_exp[i] = im->exp[i]; */

  // verify signature

  // sign header
  // PRGinit(rseed, 20, rprg);

  encrypt();

  // check for signature match
  for (i = 0; i < N; i++) {
    P0 = ((unsigned char*)decrypted)[i];
    if (((unsigned char*)decrypted)[i] != exp_reg_m[i]) {
      P1 = ((unsigned char*)decrypted)[i];
      //      P2 = sig[i];
      good = 0;
      break;
    }
  }

  P0 = good;
  quit();
}
