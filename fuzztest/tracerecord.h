#ifndef __TRACERECORD_H__
#define __TRACERECORD_H__

#include "tracegen.h"
#include "secureboot.h"

class TraceGenerator {
    static const int DEBUG_REG_ADDR;
    static const int DEBUG_REG_DATA;

    static uint32_t trid;

public:
    static void tracegen_aes(std::shared_ptr<Voc8051_tb> top, std::shared_ptr<TraceGen> tg);

};

#endif
