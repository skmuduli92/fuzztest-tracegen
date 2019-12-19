// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vsecret_impl_H_
#define _Vsecret_impl_H_

#include "verilated_heavy.h"

class Vsecret_impl_PSfoAy;

//----------

VL_MODULE(Vsecret_impl) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint all: 
    VL_IN8(clk,0,0);
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(x,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint all: 
    VL_SIG(PSLcz0,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint all: 
    VL_SIG8(PSWqdZ,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsecret_impl_PSfoAy* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsecret_impl);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vsecret_impl(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsecret_impl();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void PSW5Ub(Vsecret_impl_PSfoAy* __restrict vlSymsp);
  public:
    void PSz5AI(Vsecret_impl_PSfoAy* symsp, bool first);
  private:
    static QData PSrKVU(Vsecret_impl_PSfoAy* __restrict vlSymsp);
    void PSNLLT() VL_ATTR_COLD;
  public:
    static void PSc1JR(Vsecret_impl_PSfoAy* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void PSkged();
#endif // VL_DEBUG
  public:
    static void PSguha(Vsecret_impl_PSfoAy* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSfsMM(Vsecret_impl_PSfoAy* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSlNA1(Vsecret_impl_PSfoAy* __restrict vlSymsp) VL_ATTR_COLD;
    static void PS63Ll(Vsecret_impl_PSfoAy* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
