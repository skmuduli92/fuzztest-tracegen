// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint all: 
    VL_IN8(clk,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint all: 
    VL_SIG(top__DOT__cyc,31,0);
    VL_SIG(top__DOT__a,31,0);
    VL_SIG(top__DOT__b,31,0);
    VL_SIG(top__DOT__secret__DOT__x_combo___05FV,31,0);
    VL_SIG(top__DOT__secret__DOT__x_seq___05FV,31,0);
    VL_SIG(top__DOT__secret__DOT__x_tmp___05FV,31,0);
    VL_SIG64(top__DOT__secret__DOT__handle___05FV,63,0);
    VL_SIG64(top__DOT__secret__DOT__last_combo_seqnum___05FV,63,0);
    VL_SIG64(top__DOT__secret__DOT__last_seq_seqnum___05FV,63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint all: 
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG(__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x,31,0);
    VL_SIG(__Vdly__top__DOT__a,31,0);
    VL_SIG(__Vdly__top__DOT__b,31,0);
    VL_SIG64(__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout,63,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_check_hash_TOP(const IData protectlib_hash___05FV);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_ignore_TOP(const QData handle___05FV, const IData a, const IData b);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update_TOP(const QData handle___05FV, const IData a, const IData b, IData& x, QData& verilated_secret_protectlib_combo_update__Vfuncrtn);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_create_TOP(const std::string& scope___05FV, QData& verilated_secret_protectlib_create__Vfuncrtn);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_final_TOP(const QData handle___05FV);
    void __Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update_TOP(const QData handle___05FV, IData& x, const CData clk, QData& verilated_secret_protectlib_seq_update__Vfuncrtn);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _final_TOP(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
