#ifndef _TAMPER_H_DEFINED_
#define _TAMPER_H_DEFINED_

#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

// Interface for tampering.
struct ITamperer {
    virtual void tamper(Voc8051_tb* top);
};

// One of the tamperers
struct NopTamperer : public ITamperer {
  const unsigned BASE_ADDR;
  const unsigned BUF_SIZE;

  NopTamperer(unsigned baseaddr, unsigned bufsz)
    : BASE_ADDR(baseaddr)
    , BUF_SIZE(bufsz)
  {
  }

  virtual void tamper(Voc8051_tb* top);
};

#endif
