#include <stdio.h>

#include "tamper.h"

#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

// Default tamper function.
void ITamperer::tamper(Voc8051_tb* top) 
{
  // do nothing.
  (void) top;
}

void NopTamperer::tamper(Voc8051_tb* top)
{
  for(unsigned i=0; i < BUF_SIZE; i++) {
    int data;
    if (scanf("%u",  &data) != 1)  { break; }
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[i + BASE_ADDR] = data;
  }
}

