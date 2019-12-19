// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../make_protect_lib/top.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../make_protect_lib/top.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_check_hash_TOP(const IData protectlib_hash___05FV) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_check_hash_TOP\n"); );
    // Body
    int protectlib_hash___05FV__Vcvt;
    protectlib_hash___05FV__Vcvt = protectlib_hash___05FV;
    verilated_secret_protectlib_check_hash(protectlib_hash___05FV__Vcvt);
}

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_create_TOP(const std::string& scope___05FV, QData& verilated_secret_protectlib_create__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_create_TOP\n"); );
    // Body
    const char* scope___05FV__Vcvt;
    scope___05FV__Vcvt = scope___05FV.c_str();
    void* verilated_secret_protectlib_create__Vfuncrtn__Vcvt = verilated_secret_protectlib_create(scope___05FV__Vcvt);
    verilated_secret_protectlib_create__Vfuncrtn = 
        VL_CVT_VP_Q(verilated_secret_protectlib_create__Vfuncrtn__Vcvt);
}

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update_TOP(const QData handle___05FV, const IData a, const IData b, IData& x, QData& verilated_secret_protectlib_combo_update__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update_TOP\n"); );
    // Body
    void* handle___05FV__Vcvt;
    handle___05FV__Vcvt = VL_CVT_Q_VP(handle___05FV);
    svLogicVecVal a__Vcvt [1];
    VL_SET_SVLV_I(32, a__Vcvt, a);
    svLogicVecVal b__Vcvt [1];
    VL_SET_SVLV_I(32, b__Vcvt, b);
    svLogicVecVal x__Vcvt [1];
    long long verilated_secret_protectlib_combo_update__Vfuncrtn__Vcvt = verilated_secret_protectlib_combo_update(handle___05FV__Vcvt, a__Vcvt, b__Vcvt, x__Vcvt);
    x = VL_SET_I_SVLV(x__Vcvt);
    verilated_secret_protectlib_combo_update__Vfuncrtn 
        = verilated_secret_protectlib_combo_update__Vfuncrtn__Vcvt;
}

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update_TOP(const QData handle___05FV, IData& x, const CData clk, QData& verilated_secret_protectlib_seq_update__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update_TOP\n"); );
    // Body
    void* handle___05FV__Vcvt;
    handle___05FV__Vcvt = VL_CVT_Q_VP(handle___05FV);
    svLogicVecVal x__Vcvt [1];
    unsigned char clk__Vcvt;
    clk__Vcvt = clk;
    long long verilated_secret_protectlib_seq_update__Vfuncrtn__Vcvt = verilated_secret_protectlib_seq_update(handle___05FV__Vcvt, x__Vcvt, clk__Vcvt);
    x = VL_SET_I_SVLV(x__Vcvt);
    verilated_secret_protectlib_seq_update__Vfuncrtn 
        = verilated_secret_protectlib_seq_update__Vfuncrtn__Vcvt;
}

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_ignore_TOP(const QData handle___05FV, const IData a, const IData b) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_ignore_TOP\n"); );
    // Body
    void* handle___05FV__Vcvt;
    handle___05FV__Vcvt = VL_CVT_Q_VP(handle___05FV);
    svLogicVecVal a__Vcvt [1];
    VL_SET_SVLV_I(32, a__Vcvt, a);
    svLogicVecVal b__Vcvt [1];
    VL_SET_SVLV_I(32, b__Vcvt, b);
    verilated_secret_protectlib_combo_ignore(handle___05FV__Vcvt, a__Vcvt, b__Vcvt);
}

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_final_TOP(const QData handle___05FV) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_final_TOP\n"); );
    // Body
    void* handle___05FV__Vcvt;
    handle___05FV__Vcvt = VL_CVT_Q_VP(handle___05FV);
    verilated_secret_protectlib_final(handle___05FV__Vcvt);
}

void Vtop::_final_TOP(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_final_TOP\n"); );
    // Variables
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_final_TOP(vlTOPp->top__DOT__secret__DOT__handle___05FV);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG(__Vdly__top__DOT__cyc,31,0);
    // Body
    __Vdly__top__DOT__cyc = vlTOPp->top__DOT__cyc;
    vlTOPp->__Vdly__top__DOT__b = vlTOPp->top__DOT__b;
    vlTOPp->__Vdly__top__DOT__a = vlTOPp->top__DOT__a;
    VL_WRITEF("[%0t] cyc=%0d a=%0# b=%0# x=%0#\n",64,
              VL_TIME_Q(),32,vlTOPp->top__DOT__cyc,
              32,vlTOPp->top__DOT__a,32,vlTOPp->top__DOT__b,
              32,((vlTOPp->top__DOT__secret__DOT__last_seq_seqnum___05FV 
                   > vlTOPp->top__DOT__secret__DOT__last_combo_seqnum___05FV)
                   ? vlTOPp->top__DOT__secret__DOT__x_seq___05FV
                   : vlTOPp->top__DOT__secret__DOT__x_combo___05FV));
    __Vdly__top__DOT__cyc = ((IData)(1U) + vlTOPp->top__DOT__cyc);
    if ((0U == vlTOPp->top__DOT__cyc)) {
        vlTOPp->__Vdly__top__DOT__a = 5U;
        vlTOPp->__Vdly__top__DOT__b = 7U;
    } else {
        if ((1U == vlTOPp->top__DOT__cyc)) {
            vlTOPp->__Vdly__top__DOT__a = 6U;
            vlTOPp->__Vdly__top__DOT__b = 2U;
        } else {
            if ((2U == vlTOPp->top__DOT__cyc)) {
                vlTOPp->__Vdly__top__DOT__a = 1U;
                vlTOPp->__Vdly__top__DOT__b = 9U;
            } else {
                if (VL_UNLIKELY(VL_LTS_III(1,32,32, 3U, vlTOPp->top__DOT__cyc))) {
                    VL_WRITEF("Done\n");
                    VL_FINISH_MT("../make_protect_lib/top.v", 30, "");
                }
            }
        }
    }
    vlTOPp->top__DOT__cyc = __Vdly__top__DOT__cyc;
}

void Vtop::_initial__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG64(__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_create__1__Vfuncout,63,0);
    // Body
    vlTOPp->top__DOT__cyc = 0U;
    vlTOPp->top__DOT__a = 0U;
    vlTOPp->top__DOT__b = 0U;
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_check_hash_TOP(0x4ac9c416U);
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_create_TOP(VL_SFORMATF_NX("%Ntop.secret",
                                                                                vlSymsp->name()) , __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_create__1__Vfuncout);
    vlTOPp->top__DOT__secret__DOT__handle___05FV = __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_create__1__Vfuncout;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG(__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__x,31,0);
    VL_SIG64(__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__Vfuncout,63,0);
    // Body
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_ignore_TOP(vlTOPp->top__DOT__secret__DOT__handle___05FV, vlTOPp->top__DOT__a, vlTOPp->top__DOT__b);
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update_TOP(vlTOPp->top__DOT__secret__DOT__handle___05FV, __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__x, (IData)(vlTOPp->clk), __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__Vfuncout);
    vlTOPp->top__DOT__secret__DOT__x_tmp___05FV = __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__x;
    vlTOPp->top__DOT__secret__DOT__last_seq_seqnum___05FV 
        = __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_seq_update__4__Vfuncout;
    vlTOPp->top__DOT__secret__DOT__x_seq___05FV = vlTOPp->top__DOT__secret__DOT__x_tmp___05FV;
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update_TOP(vlTOPp->top__DOT__secret__DOT__handle___05FV, vlTOPp->top__DOT__a, vlTOPp->top__DOT__b, vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x, vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout);
    vlTOPp->top__DOT__secret__DOT__x_combo___05FV = vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x;
    vlTOPp->top__DOT__secret__DOT__last_combo_seqnum___05FV 
        = vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__a = vlTOPp->__Vdly__top__DOT__a;
    vlTOPp->top__DOT__b = vlTOPp->__Vdly__top__DOT__b;
    vlTOPp->__Vdpiimwrap_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update_TOP(vlTOPp->top__DOT__secret__DOT__handle___05FV, vlTOPp->top__DOT__a, vlTOPp->top__DOT__b, vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x, vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout);
    vlTOPp->top__DOT__secret__DOT__x_combo___05FV = vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x;
    vlTOPp->top__DOT__secret__DOT__last_combo_seqnum___05FV 
        = vlTOPp->__Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_final_TOP(vlSymsp);
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    top__DOT__cyc = VL_RAND_RESET_I(32);
    top__DOT__a = VL_RAND_RESET_I(32);
    top__DOT__b = VL_RAND_RESET_I(32);
    top__DOT__secret__DOT__handle___05FV = 0;
    top__DOT__secret__DOT__x_combo___05FV = VL_RAND_RESET_I(32);
    top__DOT__secret__DOT__x_seq___05FV = VL_RAND_RESET_I(32);
    top__DOT__secret__DOT__x_tmp___05FV = VL_RAND_RESET_I(32);
    top__DOT__secret__DOT__last_combo_seqnum___05FV = VL_RAND_RESET_Q(64);
    top__DOT__secret__DOT__last_seq_seqnum___05FV = VL_RAND_RESET_Q(64);
    __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__Vfuncout = 0;
    __Vfunc_top__DOT__secret__DOT__verilated_secret_protectlib_combo_update__2__x = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__a = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__b = VL_RAND_RESET_I(32);
}
