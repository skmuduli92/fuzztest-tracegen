
#include <string>
#include <vector>
#include "secureboot.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>

#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

#define KEY_LENGTH 2048
#define PUB_EXP 3

const int TraceGenerator::DEBUG_REG_ADDR = 0xEFFC;
const int TraceGenerator::DEBUG_REG_DATA = 0xEFFE;
const int TraceGenerator::MAX_TRACES = 100;
const uint32_t TraceGenerator::RESET_TIME = 20;

void TraceGenerator::addVars(std::vector<std::string> const &intvars) {
  for (std::string const &var : intvars) {
    intvar2id[var] = int_facts.size();
    int_facts.push_back(std::ofstream(genFileName(var)));
  }
}

std::string TraceGenerator::genFileName(std::string const &varname, bool fact) {
  std::string fname = varname + "_";

  if (fact)
    fname += "true.facts";
  else
    fname += "false.facts";

  filenames.push_back(fname);
  return fname;
}

std::string TraceGenerator::genFileName(std::string const &varname) {
  std::string fname = varname + ".facts";
  filenames.push_back(fname);
  return fname;
}

void TraceGenerator::recordSignal(std::string const &sname, uint32_t traceId, uint64_t time,
                                  int64_t value) {

  if (time >= RESET_TIME) {

    if (intvar2id.find(sname) != intvar2id.end())
      int_facts[intvar2id[sname]] << traceId << "\t" << time - 20 << "\t" << value
                                  << std::endl;
  }
}

void TraceGenerator::tracegen_main(std::shared_ptr<Voc8051_tb> top) {

  switch (tracegenID) {
    case 0:
      tracegen_aes(top);
      break;

    case 1:
      tracegen_sha(top);
      break;

    case 2:
      tracegen_page_table(top);
      break;

    case 3:
      // for rsa
      break;

    case 4:
      // for wr trgen
      tracegen_wr(top);
      break;

    default:
      assert(0);
      break;
  }
}

void TraceGenerator::randomizeData(std::shared_ptr<Voc8051_tb> top) {
  switch (tracegenID) {
    case 0:
      randomizeData_aes(top);
      break;

    case 1:
      randomizeData_sha(top);
      break;

    case 2:
      randomizeData_page_table(top);
      break;

    case 3:
      randomizeData_rsa(top);
      break;

    case 4:
      // for wr trgen
      randomizeData_wr(top);
      break;

    default:
      assert(0);
      break;
  }
}

void TraceGenerator::randomizeData_exp(std::shared_ptr<Voc8051_tb> top) {

  const unsigned dataloc = 0x5000;

  const unsigned exp_reg_n = 0xFC00;    // n value
  const unsigned exp_reg_exp = 0xFB00;  // e value
  const unsigned exp_reg_m = 0xFA00;    // expected message value

  size_t pri_len;  // Length of private key
  size_t pub_len;  // Length of public key
  char *pri_key;   // Private key
  char *pub_key;   // Public key
  //  char msg[KEY_LENGTH / 8];       // Message to encrypt
  unsigned char *encrypt = NULL;  // Encrypted message
  unsigned char *decrypt = NULL;  // Decrypted message
  char *err;                      // Buffer for any error messages

  // Generate key pair
  printf("Generating RSA (%d bits) keypair...", KEY_LENGTH);
  fflush(stdout);

  RSA *keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

  // std::cout << BN_num_bits(keypair->n) << std::endl;
  // std::cout << BN_num_bits(keypair->d) << std::endl;

  unsigned char *mod = new unsigned char[256]();
  unsigned char *exp = new unsigned char[256]();

  BN_bn2bin(keypair->n, mod);
  BN_bn2bin(keypair->e, exp);

  // input byte generation
  unsigned char *ibuf = new unsigned char[256]();
  srand(time(NULL));
  for (size_t t = 0; t < 256; ++t) {
    ibuf[t] = (unsigned char)rand() % 128;
  }

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_n, mod,
              256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_exp, exp,
              256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_m, ibuf,
              256);

  // std::cout << "SHA1 value: " << std::endl;
  // for (size_t i = 0; i < 20; i++) {
  //   printf("%02x", ibuf[i]);
  // }
  // printf("\n");

  // Encrypt the message
  std::cout << "RSA key pair -> size() : " << std::dec << RSA_size(keypair) << std::endl;
  encrypt = (unsigned char *)malloc(256);
  int encrypt_len;
  err = (char *)malloc(130);
  if ((encrypt_len = RSA_public_encrypt(RSA_size(keypair), ibuf, encrypt, keypair,
                                        RSA_NO_PADDING)) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error encrypting message: %s\n", err);
  }

  std::cout << "encryption length: " << encrypt_len << std::endl;

  // Decrypt it
  decrypt = (unsigned char *)malloc(encrypt_len);
  if (RSA_private_decrypt(encrypt_len, encrypt, decrypt, keypair, RSA_NO_PADDING) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error decrypting message: %s\n", err);
  }

  // for (size_t id = 0; id < 20; ++id) printf("%02x", decrypt[id]);
  // printf("\n");

  RSA_free(keypair);
  // BIO_free_all(pub);
  // BIO_free_all(pri);
  free(pri_key);
  free(pub_key);
  free(encrypt);
  free(decrypt);
  free(err);

  delete[](mod);
  delete[](exp);
  delete[](ibuf);
}

void TraceGenerator::randomizeData_rsa(std::shared_ptr<Voc8051_tb> top) {

  const unsigned dataloc = 0x5000;

  const unsigned exp_reg_n = 0xFC00;    // n value
  const unsigned exp_reg_exp = 0xFB00;  // e value
  const unsigned exp_reg_m = 0xFA00;    // expected message value

  size_t pri_len;  // Length of private key
  size_t pub_len;  // Length of public key
  char *pri_key;   // Private key
  char *pub_key;   // Public key
  //  char msg[KEY_LENGTH / 8];       // Message to encrypt
  unsigned char *encrypt = NULL;  // Encrypted message
  unsigned char *decrypt = NULL;  // Decrypted message
  char *err;                      // Buffer for any error messages

  // Generate key pair
  printf("Generating RSA (%d bits) keypair...", KEY_LENGTH);
  fflush(stdout);

  RSA *keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

  // std::cout << BN_num_bits(keypair->n) << std::endl;
  // std::cout << BN_num_bits(keypair->d) << std::endl;

  unsigned char *mod = new unsigned char[256]();
  unsigned char *exp = new unsigned char[256]();

  BN_bn2bin(keypair->n, mod);
  BN_bn2bin(keypair->e, exp);

  // input byte generation
  unsigned char *ibuf = new unsigned char[256]();
  srand(time(NULL));
  for (size_t t = 0; t < 256; ++t) {
    ibuf[t] = (unsigned char)rand() % 128;
  }

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_n, mod,
              256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_exp, exp,
              256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_m, ibuf,
              256);

  // std::cout << "SHA1 value: " << std::endl;
  // for (size_t i = 0; i < 20; i++) {
  //   printf("%02x", ibuf[i]);
  // }
  // printf("\n");

  // Encrypt the message
  std::cout << "RSA key pair -> size() : " << std::dec << RSA_size(keypair) << std::endl;
  encrypt = (unsigned char *)malloc(256);
  int encrypt_len;
  err = (char *)malloc(130);
  if ((encrypt_len = RSA_public_encrypt(RSA_size(keypair), ibuf, encrypt, keypair,
                                        RSA_NO_PADDING)) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error encrypting message: %s\n", err);
  }

  std::cout << "encryption length: " << encrypt_len << std::endl;

  // Decrypt it
  decrypt = (unsigned char *)malloc(encrypt_len);
  if (RSA_private_decrypt(encrypt_len, encrypt, decrypt, keypair, RSA_NO_PADDING) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error decrypting message: %s\n", err);
  }

  // for (size_t id = 0; id < 20; ++id) printf("%02x", decrypt[id]);
  // printf("\n");

  RSA_free(keypair);
  // BIO_free_all(pub);
  // BIO_free_all(pri);
  free(pri_key);
  free(pub_key);
  free(encrypt);
  free(decrypt);
  free(err);

  delete[](mod);
  delete[](exp);
  delete[](ibuf);
}

void TraceGenerator::randomizeData_aes(std::shared_ptr<Voc8051_tb> top) {
  // randomize aes data length
  unsigned aes_reg_len = rand() % 128;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen = aes_reg_len;

  // randomly generate keys
  for (size_t idx = 0; idx < 4; ++idx) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_key0[idx] =
        rand() % std::numeric_limits<unsigned>::max();
  }
}

void TraceGenerator::randomizeData_sha(std::shared_ptr<Voc8051_tb> top) {
  const int dataloc = 0xE100;
  unsigned datalen;

  // TODO : fix the computation of padding for corner cases ??
  // this is to avoid those cases
  if (rand() % 2)
    datalen = rand() % 56;
  else
    datalen = rand() % 100;

  std::cout << "data length : " << std::dec << datalen << std::endl;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xFE06] = 128;

  unsigned char ibuf[128];

  for (size_t id = 0; id < 128; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + id] = 0;
    ibuf[id] = 0;
  }

  for (size_t id = 0; id < datalen; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + id] = id;
    ibuf[id] = id;
  }

  const int pyhash = 0xE300;
  unsigned char obuf[20];
  SHA1(ibuf, datalen, obuf);

  // to verify against
  for (size_t i = 0; i < 20; i++) {
    printf("%02x ", obuf[i]);
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[pyhash + i] = obuf[i];
  }

  unsigned padding = 64 - datalen % 64;
  unsigned mlen = datalen + padding;
  std::cout << "\npadding : " << std::dec << padding << ", mlen : " << mlen << std::endl;
  std::cout << std::dec << ((datalen << 3) & 0xFF) << std::endl;
  std::cout << std::dec << ((datalen >> 5) & 0xFF) << std::endl;
  std::cout << std::dec << ((datalen >> 13) & 0xFF) << std::endl;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_len = mlen;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + datalen] =
      0x80;

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 1] =
      (datalen << 3) & 0xFF;

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 2] =
      (datalen >> 5) & 0xFF;

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 3] =
      (datalen >> 13) & 0xFF;
}

void TraceGenerator::randomizeData_wr(std::shared_ptr<Voc8051_tb> top) {
  for (size_t id = 0; id < 32; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[id] = 0xFF;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[id] = 0xFF;
  }

  // print the memwr_reg_state status to check if it is actually set during the process
  // check the memwr reg len as well

  // this will enable tampering using FSM_writer in SoC
  const int BUF_SIZE = 16;

  const unsigned int start_addr = 0x0000;
  const unsigned int end_addr = 0x0800;
  const unsigned int dest_addr = 0x1000;

  const unsigned int datasrc = 0x0000;
  const unsigned int datadst = 0x1000;

  for (size_t i = 0; i < BUF_SIZE; i++) {

    uint8_t data = rand() % std::numeric_limits<uint8_t>::max();
    uint16_t addr = start_addr + (rand() % (end_addr - start_addr));

    top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_addr[i] = addr;
    top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_data[i] = data;
    top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_delay[i] = 0;
  }

  // initialising source address with some data and dest address with all 0s
  // for (size_t id = 0; id < 64; ++id) {
  //   top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[start_addr] = i;
  //   top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dest_addr] = 0x00;
  // }

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__start_op = 0x01;
  // top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_rd_addr = datasrc;
  // top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_wr_addr = datadst;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xEFFE] =
      2 + (rand() % 62);
}

void TraceGenerator::randomizeData_page_table(std::shared_ptr<Voc8051_tb> top) {
  // create a map with data region and corresponding page table entry location
  std::vector<std::pair<unsigned, unsigned>> addr_range(3);
  addr_range[0] = std::make_pair(0x00, 0x0000);
  addr_range[1] = std::make_pair(0x01, 0x0800);
  addr_range[2] = std::make_pair(0x02, 0x1000);

  const unsigned read_mode = 0xEFF2;
  const unsigned write_mode = 0xEFF6;
  const unsigned xram_segment = 0XEFEE;

  const unsigned mem_addr = 0xEFFA;
  const unsigned mem_data = 0XEFFE;

  const unsigned read_succeed = (0xEFE6);
  const unsigned write_succeed = (0xEFEA);

  unsigned segid = rand() % 3;
  unsigned segment = addr_range[segid].first;
  unsigned offset = (rand() % 128);
  unsigned abs_addr = addr_range[segid].second + offset;
  addr_store = abs_addr;

  std::cout << "absolute address : " << (uint32_t)abs_addr << std::endl;

  unsigned action = rand() % 4;
  std::cout << "action : " << action << std::endl;
  std::cout << "segment : " << segment << std::endl;
  std::cout << "abs addrss : " << abs_addr << std::endl;
  switch (action) {
    case 0:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled
          [segment] = 0x00;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled
          [segment] = 0x00;
      break;

    case 1:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled
          [segment] = 0x00;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled
          [segment] = 0x01;

      break;

    case 2:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled
          [segment] = 0x01;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled
          [segment] = 0x00;

      break;

    case 3:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled
          [segment] = 0x01;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled
          [segment] = 0x01;

      break;

    default:
      assert(0);
      break;
  }

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[xram_segment] = segment;

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[mem_addr] = offset;

  // initializing memory location with some data
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[abs_addr] = 0x01;

  // data to write to memory location
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[mem_data] = 0x02;
}

void TraceGenerator::tracegen_sha(std::shared_ptr<Voc8051_tb> top) {

  recordSignal(
      "sha_reg_len", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_len);

  recordSignal(
      "byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter);

  recordSignal(
      "byte_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next);

  recordSignal(
      "sha_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_state);

  recordSignal(
      "sha_state_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_state_next);

  recordSignal(
      "byte_counter_next_rw", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next_rw);

  recordSignal(
      "ready_flag", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha1_core_i__DOT__ready_flag);

  recordSignal(
      "reg_bytes_read", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__reg_bytes_read);

  recordSignal(
      "bytes_read_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__bytes_read_next);

  recordSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter);

  recordSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter_next);

  recordSignal(
      "sha_reg_rd_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_rd_addr);

  recordSignal(
      "sha_reg_wr_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_wr_addr);

  recordSignal(
      "sha_more_blocks", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_more_blocks);

  recordSignal(
      "sha_core_init", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_init);

  recordSignal(
      "sha_core_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_next);

  recordSignal(
      "sha_core_ready_r", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_ready_r);

  recordSignal(
      "good_value", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA]);
}

void TraceGenerator::tracegen_aes(std::shared_ptr<Voc8051_tb> top) {
  // substracting 20 for reset time

  recordSignal("ack_aes", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__ack_aes);

  recordSignal("aes_xram_ack", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_xram_ack);

  recordSignal(
      "aes_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state);

  recordSignal(
      "aes_reg_state_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state_next);

  recordSignal(
      "aes_byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__byte_counter);

  recordSignal(
      "aes_reg_oplen: ", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  recordSignal(
      "aes_data_out_mux", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_ctr_i__DOT__data_out_mux);

  recordSignal(
      "good_value", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA]);

  recordSignal(
      "aes_reg_oplen", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  recordSignal(
      "operated_bytes_count", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count);

  recordSignal(
      "operated_bytes_count_next", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count_next);

  recordSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter);

  recordSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter_next);

  recordSignal("aes_reg_start", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__start_op);
}

void TraceGenerator::tracegen_wr(std::shared_ptr<Voc8051_tb> top) {

  std::vector<std::pair<std::string, uint32_t>> signalvals(
      {{"memwr_start_op", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__start_op},
       {"memwr_reg_state",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_state},
       {"mem_reg_rd_addr",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_rd_addr},
       {"mem_reg_wr_addr",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_wr_addr},
       {"memwr_reg_bytes_written",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__reg_bytes_written},
       {"memwr_reg_bytes_read",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__reg_bytes_read},
       {"memwr_reg_bytes_read_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__bytes_read_next},
       {"memwr_reg_bytes_written_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__bytes_written_next},
       {"memwr_reg_len",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__memwr_reg_len},
       {"memwr_wren", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__wren},
       {"memwr_state_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_i__DOT__state_next},
       {"memwr_xram_ack", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_xram_ack},
       {"memwr_xram_stb", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__memwr_xram_stb},
       {"ack_memwr", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__ack_memwr},
       {"stb_memwr", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__stb_memwr},
       {"fsm_writer_finished", top->oc8051_tb__DOT__fsm_writer_i__DOT__finished},
       {"fsm_writer_ptr", top->oc8051_tb__DOT__fsm_writer_i__DOT__ptr},
       {"fsm_writer_delay", top->oc8051_tb__DOT__fsm_writer_i__DOT__delay},
       {"procarbiter_arbiter_state",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_procarbiter_i__DOT__arbiter_state},
       {"procarbiter_arbit_hold",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_procarbiter_i__DOT__arbit_holder},
       {"procarbiter_arbiter_state_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_procarbiter_i__DOT__arbiter_state_next},
       {"procarbiter_arbit_winner",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_procarbiter_i__DOT__arbit_winner},
       {"procarbiter_arbit_holder_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_procarbiter_i__DOT__arbit_holder_next},
       {"memarbiter_arbiter_state",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_memarbiter_i__DOT__arbiter_state},
       {"memarbiter_arbit_holder",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_memarbiter_i__DOT__arbit_holder},
       {"memarbiter_arbiter_state_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_memarbiter_i__DOT__arbiter_state_next},
       {"memarbiter_arbit_winner",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_memarbiter_i__DOT__arbit_winner},
       {"memarbiter_arbit_holder_next",
        top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_memarbiter_i__DOT__arbit_holder_next},
       {"xram_ackw", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackw},
       {"xram_ackr", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackr},
       {"xram_cnt", top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__cnt}});

  for (std::pair<std::string, uint32_t> sp : signalvals)
    recordSignal(sp.first, trid, sc_time_stamp(), sp.second);
}

void TraceGenerator::tracegen_page_table(std::shared_ptr<Voc8051_tb> top) {
  const unsigned read_succeed = (0xEFE6);
  const unsigned write_succeed = (0xEFEA);

  std::vector<std::string> signals(
      {"read_succeed",   "write_succeed", "wr_addr",       "rd_addr",      "ack_w",
       "ack_r",          "ia_addr_reg",   "pc_ia_reg",     "ia_reg_next",  "pt_in_wr_range",
       "pt_in_rd_range", "pt_wr_reg_use", "pt_rd_reg_use", "ia_rwn_reg",   "illegal_src",
       "illegal_wr",     "illegal_rd",    "accesser",      "ia_src_next",  "wr_enabled_0",
       "wr_enabled_1",   "wr_enabled_2",  "rd_enabled_0",  "rd_enabled_1", "rd_enabled_2"});

  std::vector<uint32_t> values(
      {top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[read_succeed],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[write_succeed],
       top->oc8051_tb__DOT__oc8051_top_1__DOT__wr_addr,
       top->oc8051_tb__DOT__oc8051_top_1__DOT__rd_addr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackw,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_addr_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pc_ia_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_reg_next,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_in_wr_range,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_in_rd_range,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_wr_reg_use,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_rd_reg_use,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_rwn_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_src,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_wr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_rd,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__accesser,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_src_next,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[0],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[1],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[2],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[0],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[1],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[2]});

  if (signals.size() != values.size()) {
    std::cerr << "SIGNALS AND VALUES VECTOR SIZE MISMATCH" << std::endl;
    exit(1);
  }

  for (size_t xid = 0; xid < signals.size(); ++xid) {
    recordSignal(signals[xid], trid, sc_time_stamp(), values[xid]);
  }
}
