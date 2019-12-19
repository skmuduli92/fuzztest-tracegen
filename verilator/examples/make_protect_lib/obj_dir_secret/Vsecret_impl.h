// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vsecret_impl_H_
#define _Vsecret_impl_H_

#include "verilated_heavy.h"

class Vsecret_impl_PSUCik;

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
    VL_SIG(PSQtCi,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint all: 
    VL_SIG8(PSdN9F,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsecret_impl_PSUCik* __VlSymsp;  // Symbol table
    
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
    static void PSSjPq(Vsecret_impl_PSUCik* __restrict vlSymsp);
  public:
    void PSroGv(Vsecret_impl_PSUCik* symsp, bool first);
  private:
    static QData PSA8cC(Vsecret_impl_PSUCik* __restrict vlSymsp);
    void PSw2N2() VL_ATTR_COLD;
  public:
    static void PSNoq6(Vsecret_impl_PSUCik* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void PSAFl4();
#endif // VL_DEBUG
  public:
    static void PSyVpu(Vsecret_impl_PSUCik* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSD5AJ(Vsecret_impl_PSUCik* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSDi4J(Vsecret_impl_PSUCik* __restrict vlSymsp) VL_ATTR_COLD;
    static void PS67EA(Vsecret_impl_PSUCik* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
