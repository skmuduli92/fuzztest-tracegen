
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
      std::cout << "calling randomize data" << std::endl;
      randomizeData_rsa(top);
      break;

    case 4:
      // for wr trgen
      randomizeData_wr(top);
      break;

    case 5:
      // for trapping microcontroaller interfaces during aes
      randomizeData_aes(top);
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
  // printf("Generating RSA (%d bits) keypair...", KEY_LENGTH);
  // fflush(stdout);

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

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_n, mod, 256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_exp, exp, 256);

  std::memcpy(top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__exp_reg_m, ibuf, 256);

  // Encrypt the message
  std::cout << "RSA key pair -> size() : " << std::dec << RSA_size(keypair) << std::endl;
  encrypt = (unsigned char *)malloc(256);
  int encrypt_len;
  err = (char *)malloc(130);
  if ((encrypt_len = RSA_public_encrypt(RSA_size(keypair), ibuf, encrypt, keypair, RSA_NO_PADDING)) == -1) {
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
  size_t pri_len;  // Length of private key
  size_t pub_len;  // Length of public key
  char *pri_key;   // Private key
  char *pub_key;   // Public key
  //  char msg[KEY_LENGTH / 8];       // Message to encrypt
  unsigned char *encrypt = NULL;  // Encrypted message
  unsigned char *decrypt = NULL;  // Decrypted message
  char *err;                      // Buffer for any error messages

  // Generate key pair
  // printf("Generating RSA (%d bits) keypair...", KEY_LENGTH);
  // fflush(stdout);

  RSA *keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

  // std::cout << "generated keys" << std::endl;

  unsigned char *n = new unsigned char[256]();
  unsigned char *e = new unsigned char[256]();

  BN_bn2bin(keypair->n, n);
  BN_bn2bin(keypair->e, e);

  // std::cout << "exp : " << std::endl;
  // for (size_t t = 0; t < 256; ++t) {
  //   std::cout << std::hex << (uint32_t)e[t];
  //   if (t % 24 == 0) std::cout << std::endl;
  // }

  // std::cout << "\nmod(n) : " << std::endl;
  // for (size_t t = 0; t < 256; ++t) {
  //   std::cout << std::hex << (uint32_t)n[t];
  //   if (t % 24 == 0) std::cout << std::endl;
  // }

  // std::cout << std::endl;

  // input byte generation
  unsigned char *ibuf = new unsigned char[256]();
  srand(time(NULL));
  for (size_t t = 0; t < 256; ++t) {
    uint8_t data;
    int dataread = fread(&data, sizeof(data), 1, insource);
    if (dataread == 0) {
      std::cout << "Error : reading data in rsa testing\n";
      exit(1);
    }

    ibuf[t] = data % 128;
  }
  //
  // std::cout << "\ngenerated ibuf\n";
  // std::cout << "updated parameter values in memory" << std::endl;
  //
  // std::cout << "ibuf message vlaue: " << std::endl;
  // for (size_t id = 0; id < 256; ++id) std::cout << std::hex << (uint32_t)ibuf[id];
  //
  // std::cout << std::endl;

  // Encrypt the message
  // std::cout << "RSA key pair -> size() : " << std::dec << RSA_size(keypair) << std::endl;
  encrypt = (unsigned char *)malloc(256);
  int encrypt_len;
  err = (char *)malloc(130);
  if ((encrypt_len = RSA_public_encrypt(RSA_size(keypair), ibuf, encrypt, keypair, RSA_NO_PADDING)) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error encrypting message: %s\n", err);
  }

  // std::cout << "encryption length: " << encrypt_len << std::endl;

  // for (size_t id = 0; id < 256; ++id) printf("%02x", encrypt[id]);
  // printf("\n");

  // Decrypt it
  decrypt = (unsigned char *)malloc(encrypt_len);
  if (RSA_private_decrypt(encrypt_len, encrypt, decrypt, keypair, RSA_NO_PADDING) == -1) {
    // ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    fprintf(stderr, "Error decrypting message: %s\n", err);
  }

  // std::cout << "decrypted text: " << std::endl;
  // for (size_t id = 0; id < 256; ++id) printf("%02x", decrypt[id]);
  // printf("\n");

  // copying data to soc peripherals

  for (size_t id = 0; id < 32; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[id] = 0xFF;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[id] = 0xFF;
  }

  // __xdata __at(0xF000) unsigned char vn[256];
  // __xdata __at(0xF100) unsigned char vexp[256];
  // __xdata __at(0xF200) unsigned char vm[256];
  // __xdata __at(0xF300) unsigned char vdata[256];

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__start_op = 1;

  for (size_t i = 0; i < 256; ++i) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xF000 + i] = n[i];
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xF100 + i] = e[i];
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xF200 + i] = encrypt[i];
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xF300 + i] = decrypt[i];
  }

  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__modexp_top_i__DOT__start_op = 0x01;

  // std::cout << "encrypt : " << std::endl;
  // for (size_t t = 0; t < 256; ++t) {
  //   std::cout << std::hex << (uint32_t)encrypt[t];
  //   if (t % 24 == 0) std::cout << std::endl;
  // }

  // std::cout << "\n\ndecrypt : " << std::endl;
  // for (size_t t = 0; t < 256; ++t) {
  //   std::cout << std::hex << (uint32_t)decrypt[t];
  //   if (t % 24 == 0) std::cout << std::endl;
  // }

  RSA_free(keypair);
  // BIO_free_all(pub);
  // BIO_free_all(pri);
  free(pri_key);
  free(pub_key);
  free(encrypt);
  free(decrypt);
  free(err);

  delete[](n);
  delete[](e);
  delete[](ibuf);
}

void TraceGenerator::randomizeData_aes(std::shared_ptr<Voc8051_tb> top) {

  // enable read/write for each location in page table
  for (size_t id = 0; id < 32; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[id] = 0xFF;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[id] = 0xFF;
  }

  // randomize aes data length
  unsigned aes_reg_len = 0;
  unsigned tempdata = 0;

  // randomly generate keys
  for (size_t idx = 0; idx < 4; ++idx) {
    // std::cin >> tempdata;
    if (fread(&tempdata, sizeof(tempdata), 1, insource) != 1) {
      std::cout << "wrong key data : " << idx << "\n";
      exit(1);
    }
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_key0[idx] = tempdata;
  }

  for (size_t idx = 0; idx < 4; ++idx) {
    if (fread(&tempdata, sizeof(tempdata), 1, insource) != 1) {
      std::cout << "wrong ctr data\n";
      exit(1);
    }

    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_ctr[idx] = tempdata;
  }

  // std::cin >> aes_reg_len;

  if (fread(&aes_reg_len, sizeof(aes_reg_len), 1, insource) != 1) {
    std::cout << "reg len\n";
    exit(1);
  }

  aes_reg_len = aes_reg_len % 1024;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen = aes_reg_len;

  const unsigned int dataloc = 0xE000;
  const unsigned int vdataloc = 0xE400;
  uint8_t plaindata;
  for (size_t idx = 0; idx < 1024; ++idx) {
    if (idx < aes_reg_len) {

      if (fread(&plaindata, sizeof(plaindata), 1, insource) != 1) {
        std::cout << "wrong plain data : " << idx << "\n";
        exit(1);
      }

      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[vdataloc + idx] = (uint8_t)plaindata;
    } else
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[vdataloc + idx] = 0x00;
  }

  std::cout << "READING COMPLETE\n";
}

void TraceGenerator::randomizeData_sha(std::shared_ptr<Voc8051_tb> top) {
  const int dataloc = 0xE400;

  unsigned datalen;

  // TODO : fix the computation of padding for corner cases ??
  // this is to avoid those cases

  if (fread(&datalen, sizeof(datalen), 1, insource) != 1) {
    std::cout << "ERROR : no input supplied\n";
    exit(1);
  }

  // int bytes = fscanf(stdin, "%u", &datalen);
  // if (bytes == 0) {
  //   std::cout << "ERROR : no input supplied\n";
  //   exit(1);
  // }

  if (rand() % 2)
    datalen = rand() % 56;
  else
    datalen = rand() % 100;

  // std::cout << "data length : " << std::dec << datalen << std::endl;
  // top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xFE06] = datalen;

  unsigned char ibuf[128];

  // initializing buffers
  for (size_t id = 0; id < 128; ++id) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + id] = 0;
    ibuf[id] = 0;
  }

  uint8_t data;
  for (size_t id = 0; id < datalen; ++id) {
    if (fread(&data, sizeof(data), 1, insource) != 1) {
      std::cout << "ERROR : no input supplied\n";
      exit(1);
    }

    // int bytes = fscanf(stdin, "%cu", &data);
    // if (bytes == 0) {
    //   std::cout << "ERROR : no input supplied\n";
    //   exit(1);
    // }

    ibuf[id] = data;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + id] = data;
    std::cout << std::hex << (uint32_t)data << ", ";
  }

  std::cout << std::dec << std::endl;

  const int pyhash = 0xE300;
  unsigned char obuf[20];
  SHA1(ibuf, datalen, obuf);

  // to verify against
  std::cout << "OUTPUT BUFFER : " << std::endl;
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
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + datalen] = 0x80;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 1] = (datalen << 3) & 0xFF;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 2] = (datalen >> 5) & 0xFF;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[dataloc + mlen - 3] = (datalen >> 13) & 0xFF;

  std::cout << "Simulate SHA core in SoC" << std::endl;
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

    // uint8_t data = rand() % std::numeric_limits<uint8_t>::max();
    uint8_t data = 0;
    uint16_t offset = 0x00;

    int dataread = fread(&data, sizeof(data), 1, insource);
    int offsetread = fread(&offset, sizeof(offset), 1, insource);

    if (!(dataread && offsetread)) {
      std::cerr << "Error : reading from source failed\n";
      exit(1);
    }

    uint16_t addr = start_addr + (offset % (end_addr - start_addr));

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
  // top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[0xEFFE] =
  //     2 + (rand() % 62);
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

  unsigned segid = 0;
  unsigned offset = 0;
  unsigned action = 0;

  int segread = fread(&segid, sizeof(segid), 1, insource);
  int offsetread = fread(&offset, sizeof(offset), 1, insource);
  int actionread = fread(&action, sizeof(action), 1, insource);

  std::cout << "READING DATA COMPLETE\n";

  if (!(segread && offsetread && actionread)) {
    std::cout << "Error : reading input from source\n";
    exit(1);
  }

  segid = segid % 3;
  offset = offset % 128;
  action = action % 4;

  unsigned segment = addr_range[segid].first;
  unsigned abs_addr = addr_range[segid].second + offset;
  addr_store = abs_addr;

  std::cout << "absolute address : " << (uint32_t)abs_addr << std::endl;

  std::cout << "action : " << action << std::endl;
  std::cout << "segment : " << segment << std::endl;
  std::cout << "abs addrss : " << abs_addr << std::endl;

  switch (action) {
    case 0:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[segment] = 0x00;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[segment] = 0x00;
      break;

    case 1:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[segment] = 0x00;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[segment] = 0x01;

      break;

    case 2:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[segment] = 0x01;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[segment] = 0x00;

      break;

    case 3:
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[segment] = 0x01;
      top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[segment] = 0x01;

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
