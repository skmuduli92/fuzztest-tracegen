#ifndef __TRACERECORD_H__
#define __TRACERECORD_H__

#include "secureboot.h"
#include "tracegen.h"

class TraceGenerator {
 public:
  static const int DEBUG_REG_ADDR;
  static const int DEBUG_REG_DATA;
  static const int MAX_TRACES;
  static uint32_t trid;
  static void tracegen_aes(std::shared_ptr<Voc8051_tb> top, std::shared_ptr<TraceGen> tg);
};

#endif
