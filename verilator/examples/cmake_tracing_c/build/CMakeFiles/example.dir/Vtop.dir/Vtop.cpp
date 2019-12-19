// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"


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
    _configure_coverage(vlSymsp, first);
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

// Coverage
void Vtop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    static uint32_t fake_zero_count = 0;
    if (!enable) countp = &fake_zero_count;
    *countp = 0;
    VL_COVER_INSERT(countp,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp);
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../make_tracing_c/../make_tracing_c/top.v", 10, "",
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
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("../make_tracing_c/../make_tracing_c/top.v", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("[%0t] Model running...\n\n",64,VL_TIME_Q());
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIGW(__Vtemp2,95,0,3);
    VL_SIGW(__Vtemp3,95,0,3);
    // Body
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->fastclk) ^ vlTOPp->top__DOT____Vtogcov__fastclk)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__fastclk = vlTOPp->fastclk;
    }
    if (((IData)(vlTOPp->reset_l) ^ vlTOPp->top__DOT____Vtogcov__reset_l)) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->top__DOT____Vtogcov__reset_l = vlTOPp->reset_l;
    }
    if ((1U & ((IData)(vlTOPp->in_small) ^ vlTOPp->top__DOT____Vtogcov__in_small))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->top__DOT____Vtogcov__in_small = ((2U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__in_small)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->in_small)));
    }
    if ((2U & ((IData)(vlTOPp->in_small) ^ vlTOPp->top__DOT____Vtogcov__in_small))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->top__DOT____Vtogcov__in_small = ((1U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__in_small)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->in_small)));
    }
    vlTOPp->out_small = ((IData)(vlTOPp->reset_l) ? 
                         (3U & ((IData)(1U) + (IData)(vlTOPp->in_small)))
                          : 0U);
    if ((1U & ((IData)(vlTOPp->in_quad) ^ (IData)(vlTOPp->top__DOT____Vtogcov__in_quad)))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffe) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | (IData)((IData)(
                                                                  (1U 
                                                                   & (IData)(vlTOPp->in_quad)))));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 1U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffd) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 1U))))) 
                                                   << 1U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 2U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffb) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 2U))))) 
                                                   << 2U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 3U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffff7) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 3U))))) 
                                                   << 3U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 4U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffef) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 4U))))) 
                                                   << 4U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 5U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffdf) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 5U))))) 
                                                   << 5U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 6U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffbf) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 6U))))) 
                                                   << 6U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 7U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffff7f) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 7U))))) 
                                                   << 7U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 8U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffeff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 8U))))) 
                                                   << 8U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 9U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffdff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 9U))))) 
                                                   << 9U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xaU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffbff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xaU))))) 
                                                   << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xbU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffff7ff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xbU))))) 
                                                   << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xcU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffefff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xcU))))) 
                                                   << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xdU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffdfff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xdU))))) 
                                                   << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xeU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffbfff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xeU))))) 
                                                   << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xfU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffff7fff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xfU))))) 
                                                   << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x10U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffeffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x10U))))) 
                                                   << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x11U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffdffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x11U))))) 
                                                   << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x12U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffbffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x12U))))) 
                                                   << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x13U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffff7ffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x13U))))) 
                                                   << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x14U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffefffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x14U))))) 
                                                   << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x15U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffdfffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x15U))))) 
                                                   << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x16U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffbfffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x16U))))) 
                                                   << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x17U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffff7fffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x17U))))) 
                                                   << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x18U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffeffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x18U))))) 
                                                   << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x19U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffdffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x19U))))) 
                                                   << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1aU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffbffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1aU))))) 
                                                   << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1bU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfff7ffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1bU))))) 
                                                   << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1cU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffefffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1cU))))) 
                                                   << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1dU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffdfffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1dU))))) 
                                                   << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1eU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffbfffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1eU))))) 
                                                   << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1fU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xff7fffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1fU))))) 
                                                   << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x20U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfeffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x20U))))) 
                                                   << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x21U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfdffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x21U))))) 
                                                   << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x22U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfbffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x22U))))) 
                                                   << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x23U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xf7ffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x23U))))) 
                                                   << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x24U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xefffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x24U))))) 
                                                   << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x25U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xdfffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x25U))))) 
                                                   << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x26U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xbfffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x26U))))) 
                                                   << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x27U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0x7fffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x27U))))) 
                                                   << 0x27U));
    }
    if ((1U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (1U & vlTOPp->in_wide[0U]));
    }
    if ((2U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (2U & vlTOPp->in_wide[0U]));
    }
    if ((4U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (4U & vlTOPp->in_wide[0U]));
    }
    if ((8U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (8U & vlTOPp->in_wide[0U]));
    }
    if ((0x10U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10U & vlTOPp->in_wide[0U]));
    }
    if ((0x20U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20U & vlTOPp->in_wide[0U]));
    }
    if ((0x40U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40U & vlTOPp->in_wide[0U]));
    }
    if ((0x80U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80U & vlTOPp->in_wide[0U]));
    }
    if ((0x100U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x100U & vlTOPp->in_wide[0U]));
    }
    if ((0x200U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x200U & vlTOPp->in_wide[0U]));
    }
    if ((0x400U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x400U & vlTOPp->in_wide[0U]));
    }
    if ((0x800U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x800U & vlTOPp->in_wide[0U]));
    }
    if ((0x1000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x1000U & vlTOPp->in_wide[0U]));
    }
    if ((0x2000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x2000U & vlTOPp->in_wide[0U]));
    }
    if ((0x4000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x4000U & vlTOPp->in_wide[0U]));
    }
    if ((0x8000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x8000U & vlTOPp->in_wide[0U]));
    }
    if ((0x10000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10000U & vlTOPp->in_wide[0U]));
    }
    if ((0x20000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20000U & vlTOPp->in_wide[0U]));
    }
    if ((0x40000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40000U & vlTOPp->in_wide[0U]));
    }
    if ((0x80000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80000U & vlTOPp->in_wide[0U]));
    }
    if ((0x100000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x100000U & vlTOPp->in_wide[0U]));
    }
    if ((0x200000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x200000U & vlTOPp->in_wide[0U]));
    }
    if ((0x400000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x400000U & vlTOPp->in_wide[0U]));
    }
    if ((0x800000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x800000U & vlTOPp->in_wide[0U]));
    }
    if ((0x1000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x1000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x2000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x2000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x4000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x4000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x8000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x8000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x10000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x20000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x40000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x80000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80000000U & vlTOPp->in_wide[0U]));
    }
    if ((1U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (1U & vlTOPp->in_wide[1U]));
    }
    if ((2U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (2U & vlTOPp->in_wide[1U]));
    }
    if ((4U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (4U & vlTOPp->in_wide[1U]));
    }
    if ((8U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (8U & vlTOPp->in_wide[1U]));
    }
    if ((0x10U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10U & vlTOPp->in_wide[1U]));
    }
    if ((0x20U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20U & vlTOPp->in_wide[1U]));
    }
    if ((0x40U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40U & vlTOPp->in_wide[1U]));
    }
    if ((0x80U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80U & vlTOPp->in_wide[1U]));
    }
    if ((0x100U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x100U & vlTOPp->in_wide[1U]));
    }
    if ((0x200U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x200U & vlTOPp->in_wide[1U]));
    }
    if ((0x400U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x400U & vlTOPp->in_wide[1U]));
    }
    if ((0x800U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x800U & vlTOPp->in_wide[1U]));
    }
    if ((0x1000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x1000U & vlTOPp->in_wide[1U]));
    }
    if ((0x2000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x2000U & vlTOPp->in_wide[1U]));
    }
    if ((0x4000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x4000U & vlTOPp->in_wide[1U]));
    }
    if ((0x8000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x8000U & vlTOPp->in_wide[1U]));
    }
    if ((0x10000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10000U & vlTOPp->in_wide[1U]));
    }
    if ((0x20000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20000U & vlTOPp->in_wide[1U]));
    }
    if ((0x40000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40000U & vlTOPp->in_wide[1U]));
    }
    if ((0x80000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80000U & vlTOPp->in_wide[1U]));
    }
    if ((0x100000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x100000U & vlTOPp->in_wide[1U]));
    }
    if ((0x200000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x200000U & vlTOPp->in_wide[1U]));
    }
    if ((0x400000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x400000U & vlTOPp->in_wide[1U]));
    }
    if ((0x800000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x800000U & vlTOPp->in_wide[1U]));
    }
    if ((0x1000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x1000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x2000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x2000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x4000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x4000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x8000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x8000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x10000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x20000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x40000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x80000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80000000U & vlTOPp->in_wide[1U]));
    }
    if ((1U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3eU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (1U & vlTOPp->in_wide[2U]));
    }
    if ((2U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3dU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (2U & vlTOPp->in_wide[2U]));
    }
    if ((4U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3bU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (4U & vlTOPp->in_wide[2U]));
    }
    if ((8U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x37U & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (8U & vlTOPp->in_wide[2U]));
    }
    if ((0x10U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x2fU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (0x10U & vlTOPp->in_wide[2U]));
    }
    if ((0x20U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x1fU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (0x20U & vlTOPp->in_wide[2U]));
    }
    vlTOPp->out_quad = ((IData)(vlTOPp->reset_l) ? 
                        (VL_ULL(0xffffffffff) & (VL_ULL(1) 
                                                 + vlTOPp->in_quad))
                         : VL_ULL(0));
    __Vtemp2[0U] = 1U;
    __Vtemp2[1U] = 0U;
    __Vtemp2[2U] = 0U;
    VL_ADD_W(3, __Vtemp3, __Vtemp2, vlTOPp->in_wide);
    vlTOPp->out_wide[0U] = ((IData)(vlTOPp->reset_l)
                             ? __Vtemp3[0U] : 0U);
    vlTOPp->out_wide[1U] = ((IData)(vlTOPp->reset_l)
                             ? __Vtemp3[1U] : 0U);
    vlTOPp->out_wide[2U] = ((IData)(vlTOPp->reset_l)
                             ? (0x3fU & __Vtemp3[2U])
                             : 0U);
    if ((1U & ((IData)(vlTOPp->out_small) ^ vlTOPp->top__DOT____Vtogcov__out_small))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->top__DOT____Vtogcov__out_small = ((2U 
                                                   & (IData)(vlTOPp->top__DOT____Vtogcov__out_small)) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->out_small)));
    }
    if ((2U & ((IData)(vlTOPp->out_small) ^ vlTOPp->top__DOT____Vtogcov__out_small))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->top__DOT____Vtogcov__out_small = ((1U 
                                                   & (IData)(vlTOPp->top__DOT____Vtogcov__out_small)) 
                                                  | (2U 
                                                     & (IData)(vlTOPp->out_small)));
    }
    if ((1U & ((IData)(vlTOPp->out_quad) ^ (IData)(vlTOPp->top__DOT____Vtogcov__out_quad)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffe) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | (IData)((IData)(
                                                                   (1U 
                                                                    & (IData)(vlTOPp->out_quad)))));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 1U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 1U))))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffd) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 1U))))) 
                                                    << 1U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 2U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 2U))))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffb) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 2U))))) 
                                                    << 2U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 3U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffff7) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 3U))))) 
                                                    << 3U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 4U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 4U))))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffef) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 4U))))) 
                                                    << 4U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 5U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 5U))))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffdf) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 5U))))) 
                                                    << 5U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 6U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 6U))))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffbf) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 6U))))) 
                                                    << 6U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 7U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 7U))))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffff7f) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 7U))))) 
                                                    << 7U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 8U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 8U))))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffeff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 8U))))) 
                                                    << 8U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 9U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 9U))))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffdff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 9U))))) 
                                                    << 9U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xaU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffbff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xaU))))) 
                                                    << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xbU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffff7ff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xbU))))) 
                                                    << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xcU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffefff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xcU))))) 
                                                    << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xdU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffdfff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xdU))))) 
                                                    << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xeU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffbfff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xeU))))) 
                                                    << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xfU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffff7fff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xfU))))) 
                                                    << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x10U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffeffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x10U))))) 
                                                    << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x11U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffdffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x11U))))) 
                                                    << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x12U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffbffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x12U))))) 
                                                    << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x13U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffff7ffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x13U))))) 
                                                    << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x14U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffefffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x14U))))) 
                                                    << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x15U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffdfffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x15U))))) 
                                                    << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x16U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffbfffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x16U))))) 
                                                    << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x17U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffff7fffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x17U))))) 
                                                    << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x18U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffeffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x18U))))) 
                                                    << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x19U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffdffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x19U))))) 
                                                    << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1aU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffbffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1aU))))) 
                                                    << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1bU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfff7ffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1bU))))) 
                                                    << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1cU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffefffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1cU))))) 
                                                    << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1dU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffdfffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1dU))))) 
                                                    << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1eU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffbfffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1eU))))) 
                                                    << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1fU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xff7fffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1fU))))) 
                                                    << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x20U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfeffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x20U))))) 
                                                    << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x21U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfdffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x21U))))) 
                                                    << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x22U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfbffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x22U))))) 
                                                    << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x23U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xf7ffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x23U))))) 
                                                    << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x24U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xefffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x24U))))) 
                                                    << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x25U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xdfffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x25U))))) 
                                                    << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x26U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xbfffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x26U))))) 
                                                    << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x27U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0x7fffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x27U))))) 
                                                    << 0x27U));
    }
    if ((1U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (1U & vlTOPp->out_wide[0U]));
    }
    if ((2U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (2U & vlTOPp->out_wide[0U]));
    }
    if ((4U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (4U & vlTOPp->out_wide[0U]));
    }
    if ((8U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (8U & vlTOPp->out_wide[0U]));
    }
    if ((0x10U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10U & vlTOPp->out_wide[0U]));
    }
    if ((0x20U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20U & vlTOPp->out_wide[0U]));
    }
    if ((0x40U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40U & vlTOPp->out_wide[0U]));
    }
    if ((0x80U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80U & vlTOPp->out_wide[0U]));
    }
    if ((0x100U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x100U & vlTOPp->out_wide[0U]));
    }
    if ((0x200U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x200U & vlTOPp->out_wide[0U]));
    }
    if ((0x400U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x400U & vlTOPp->out_wide[0U]));
    }
    if ((0x800U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x800U & vlTOPp->out_wide[0U]));
    }
    if ((0x1000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x1000U & vlTOPp->out_wide[0U]));
    }
    if ((0x2000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x2000U & vlTOPp->out_wide[0U]));
    }
    if ((0x4000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x4000U & vlTOPp->out_wide[0U]));
    }
    if ((0x8000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x8000U & vlTOPp->out_wide[0U]));
    }
    if ((0x10000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10000U & vlTOPp->out_wide[0U]));
    }
    if ((0x20000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20000U & vlTOPp->out_wide[0U]));
    }
    if ((0x40000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40000U & vlTOPp->out_wide[0U]));
    }
    if ((0x80000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80000U & vlTOPp->out_wide[0U]));
    }
    if ((0x100000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x100000U & vlTOPp->out_wide[0U]));
    }
    if ((0x200000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x200000U & vlTOPp->out_wide[0U]));
    }
    if ((0x400000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x400000U & vlTOPp->out_wide[0U]));
    }
    if ((0x800000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x800000U & vlTOPp->out_wide[0U]));
    }
    if ((0x1000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x1000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x2000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x2000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x4000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x4000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x8000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x8000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x10000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x20000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x40000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x80000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80000000U & vlTOPp->out_wide[0U]));
    }
    if ((1U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (1U & vlTOPp->out_wide[1U]));
    }
    if ((2U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (2U & vlTOPp->out_wide[1U]));
    }
    if ((4U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (4U & vlTOPp->out_wide[1U]));
    }
    if ((8U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (8U & vlTOPp->out_wide[1U]));
    }
    if ((0x10U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10U & vlTOPp->out_wide[1U]));
    }
    if ((0x20U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20U & vlTOPp->out_wide[1U]));
    }
    if ((0x40U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40U & vlTOPp->out_wide[1U]));
    }
    if ((0x80U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80U & vlTOPp->out_wide[1U]));
    }
    if ((0x100U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x100U & vlTOPp->out_wide[1U]));
    }
    if ((0x200U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x200U & vlTOPp->out_wide[1U]));
    }
    if ((0x400U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x400U & vlTOPp->out_wide[1U]));
    }
    if ((0x800U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x800U & vlTOPp->out_wide[1U]));
    }
    if ((0x1000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x1000U & vlTOPp->out_wide[1U]));
    }
    if ((0x2000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x2000U & vlTOPp->out_wide[1U]));
    }
    if ((0x4000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x4000U & vlTOPp->out_wide[1U]));
    }
    if ((0x8000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x8000U & vlTOPp->out_wide[1U]));
    }
    if ((0x10000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10000U & vlTOPp->out_wide[1U]));
    }
    if ((0x20000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20000U & vlTOPp->out_wide[1U]));
    }
    if ((0x40000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40000U & vlTOPp->out_wide[1U]));
    }
    if ((0x80000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80000U & vlTOPp->out_wide[1U]));
    }
    if ((0x100000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x100000U & vlTOPp->out_wide[1U]));
    }
    if ((0x200000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x200000U & vlTOPp->out_wide[1U]));
    }
    if ((0x400000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x400000U & vlTOPp->out_wide[1U]));
    }
    if ((0x800000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x800000U & vlTOPp->out_wide[1U]));
    }
    if ((0x1000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x1000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x2000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x2000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x4000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x4000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x8000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x8000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x10000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x20000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x40000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x80000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80000000U & vlTOPp->out_wide[1U]));
    }
    if ((1U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3eU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (1U & vlTOPp->out_wide[2U]));
    }
    if ((2U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3dU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (2U & vlTOPp->out_wide[2U]));
    }
    if ((4U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3bU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (4U & vlTOPp->out_wide[2U]));
    }
    if ((8U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x37U & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (8U & vlTOPp->out_wide[2U]));
    }
    if ((0x10U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x2fU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (0x10U & vlTOPp->out_wide[2U]));
    }
    if ((0x20U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x1fU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (0x20U & vlTOPp->out_wide[2U]));
    }
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIGW(__Vtemp8,95,0,3);
    VL_SIGW(__Vtemp9,95,0,3);
    // Body
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->fastclk) ^ vlTOPp->top__DOT____Vtogcov__fastclk)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__fastclk = vlTOPp->fastclk;
    }
    if (((IData)(vlTOPp->reset_l) ^ vlTOPp->top__DOT____Vtogcov__reset_l)) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->top__DOT____Vtogcov__reset_l = vlTOPp->reset_l;
    }
    if ((1U & ((IData)(vlTOPp->in_small) ^ vlTOPp->top__DOT____Vtogcov__in_small))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->top__DOT____Vtogcov__in_small = ((2U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__in_small)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->in_small)));
    }
    if ((2U & ((IData)(vlTOPp->in_small) ^ vlTOPp->top__DOT____Vtogcov__in_small))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->top__DOT____Vtogcov__in_small = ((1U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__in_small)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->in_small)));
    }
    vlTOPp->out_small = ((IData)(vlTOPp->reset_l) ? 
                         (3U & ((IData)(1U) + (IData)(vlTOPp->in_small)))
                          : 0U);
    if ((1U & ((IData)(vlTOPp->in_quad) ^ (IData)(vlTOPp->top__DOT____Vtogcov__in_quad)))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffe) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | (IData)((IData)(
                                                                  (1U 
                                                                   & (IData)(vlTOPp->in_quad)))));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 1U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffd) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 1U))))) 
                                                   << 1U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 2U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffffb) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 2U))))) 
                                                   << 2U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 3U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffff7) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 3U))))) 
                                                   << 3U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 4U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffef) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 4U))))) 
                                                   << 4U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 5U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffdf) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 5U))))) 
                                                   << 5U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 6U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffffbf) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 6U))))) 
                                                   << 6U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 7U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffff7f) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 7U))))) 
                                                   << 7U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 8U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffeff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 8U))))) 
                                                   << 8U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 9U)) ^ (IData)(
                                                          (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffdff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 9U))))) 
                                                   << 9U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xaU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffffbff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xaU))))) 
                                                   << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xbU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffff7ff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xbU))))) 
                                                   << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xcU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffefff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xcU))))) 
                                                   << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xdU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffdfff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xdU))))) 
                                                   << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xeU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffffbfff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xeU))))) 
                                                   << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0xfU)) ^ (IData)(
                                                            (vlTOPp->top__DOT____Vtogcov__in_quad 
                                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffff7fff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0xfU))))) 
                                                   << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x10U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffeffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x10U))))) 
                                                   << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x11U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffdffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x11U))))) 
                                                   << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x12U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffffbffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x12U))))) 
                                                   << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x13U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffff7ffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x13U))))) 
                                                   << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x14U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffefffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x14U))))) 
                                                   << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x15U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffdfffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x15U))))) 
                                                   << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x16U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffffbfffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x16U))))) 
                                                   << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x17U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffff7fffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x17U))))) 
                                                   << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x18U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffeffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x18U))))) 
                                                   << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x19U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffdffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x19U))))) 
                                                   << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1aU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfffbffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1aU))))) 
                                                   << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1bU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfff7ffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1bU))))) 
                                                   << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1cU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffefffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1cU))))) 
                                                   << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1dU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffdfffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1dU))))) 
                                                   << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1eU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xffbfffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1eU))))) 
                                                   << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x1fU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xff7fffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x1fU))))) 
                                                   << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x20U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfeffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x20U))))) 
                                                   << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x21U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfdffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x21U))))) 
                                                   << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x22U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xfbffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x22U))))) 
                                                   << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x23U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xf7ffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x23U))))) 
                                                   << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x24U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xefffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x24U))))) 
                                                   << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x25U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xdfffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x25U))))) 
                                                   << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x26U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0xbfffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x26U))))) 
                                                   << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->in_quad >> 0x27U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__in_quad 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->top__DOT____Vtogcov__in_quad = ((VL_ULL(0x7fffffffff) 
                                                 & vlTOPp->top__DOT____Vtogcov__in_quad) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlTOPp->in_quad 
                                                                               >> 0x27U))))) 
                                                   << 0x27U));
    }
    if ((1U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (1U & vlTOPp->in_wide[0U]));
    }
    if ((2U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (2U & vlTOPp->in_wide[0U]));
    }
    if ((4U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (4U & vlTOPp->in_wide[0U]));
    }
    if ((8U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (8U & vlTOPp->in_wide[0U]));
    }
    if ((0x10U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10U & vlTOPp->in_wide[0U]));
    }
    if ((0x20U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20U & vlTOPp->in_wide[0U]));
    }
    if ((0x40U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40U & vlTOPp->in_wide[0U]));
    }
    if ((0x80U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80U & vlTOPp->in_wide[0U]));
    }
    if ((0x100U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x100U & vlTOPp->in_wide[0U]));
    }
    if ((0x200U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x200U & vlTOPp->in_wide[0U]));
    }
    if ((0x400U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x400U & vlTOPp->in_wide[0U]));
    }
    if ((0x800U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x800U & vlTOPp->in_wide[0U]));
    }
    if ((0x1000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x1000U & vlTOPp->in_wide[0U]));
    }
    if ((0x2000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x2000U & vlTOPp->in_wide[0U]));
    }
    if ((0x4000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x4000U & vlTOPp->in_wide[0U]));
    }
    if ((0x8000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x8000U & vlTOPp->in_wide[0U]));
    }
    if ((0x10000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10000U & vlTOPp->in_wide[0U]));
    }
    if ((0x20000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20000U & vlTOPp->in_wide[0U]));
    }
    if ((0x40000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40000U & vlTOPp->in_wide[0U]));
    }
    if ((0x80000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80000U & vlTOPp->in_wide[0U]));
    }
    if ((0x100000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x100000U & vlTOPp->in_wide[0U]));
    }
    if ((0x200000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x200000U & vlTOPp->in_wide[0U]));
    }
    if ((0x400000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x400000U & vlTOPp->in_wide[0U]));
    }
    if ((0x800000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x800000U & vlTOPp->in_wide[0U]));
    }
    if ((0x1000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x1000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x2000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x2000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x4000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x4000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x8000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x8000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x10000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x10000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x20000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x20000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x40000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x40000000U & vlTOPp->in_wide[0U]));
    }
    if ((0x80000000U & (vlTOPp->in_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->top__DOT____Vtogcov__in_wide[0U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[0U]) 
             | (0x80000000U & vlTOPp->in_wide[0U]));
    }
    if ((1U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (1U & vlTOPp->in_wide[1U]));
    }
    if ((2U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (2U & vlTOPp->in_wide[1U]));
    }
    if ((4U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (4U & vlTOPp->in_wide[1U]));
    }
    if ((8U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (8U & vlTOPp->in_wide[1U]));
    }
    if ((0x10U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10U & vlTOPp->in_wide[1U]));
    }
    if ((0x20U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20U & vlTOPp->in_wide[1U]));
    }
    if ((0x40U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40U & vlTOPp->in_wide[1U]));
    }
    if ((0x80U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80U & vlTOPp->in_wide[1U]));
    }
    if ((0x100U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x100U & vlTOPp->in_wide[1U]));
    }
    if ((0x200U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x200U & vlTOPp->in_wide[1U]));
    }
    if ((0x400U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x400U & vlTOPp->in_wide[1U]));
    }
    if ((0x800U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x800U & vlTOPp->in_wide[1U]));
    }
    if ((0x1000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x1000U & vlTOPp->in_wide[1U]));
    }
    if ((0x2000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x2000U & vlTOPp->in_wide[1U]));
    }
    if ((0x4000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x4000U & vlTOPp->in_wide[1U]));
    }
    if ((0x8000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x8000U & vlTOPp->in_wide[1U]));
    }
    if ((0x10000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10000U & vlTOPp->in_wide[1U]));
    }
    if ((0x20000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20000U & vlTOPp->in_wide[1U]));
    }
    if ((0x40000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40000U & vlTOPp->in_wide[1U]));
    }
    if ((0x80000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80000U & vlTOPp->in_wide[1U]));
    }
    if ((0x100000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x100000U & vlTOPp->in_wide[1U]));
    }
    if ((0x200000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x200000U & vlTOPp->in_wide[1U]));
    }
    if ((0x400000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x400000U & vlTOPp->in_wide[1U]));
    }
    if ((0x800000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x800000U & vlTOPp->in_wide[1U]));
    }
    if ((0x1000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x1000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x2000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x2000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x4000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x4000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x8000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x8000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x10000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x10000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x20000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x20000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x40000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x40000000U & vlTOPp->in_wide[1U]));
    }
    if ((0x80000000U & (vlTOPp->in_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->top__DOT____Vtogcov__in_wide[1U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__in_wide[1U]) 
             | (0x80000000U & vlTOPp->in_wide[1U]));
    }
    if ((1U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3eU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (1U & vlTOPp->in_wide[2U]));
    }
    if ((2U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3dU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (2U & vlTOPp->in_wide[2U]));
    }
    if ((4U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x3bU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (4U & vlTOPp->in_wide[2U]));
    }
    if ((8U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x37U & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (8U & vlTOPp->in_wide[2U]));
    }
    if ((0x10U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x2fU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (0x10U & vlTOPp->in_wide[2U]));
    }
    if ((0x20U & (vlTOPp->in_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__in_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->top__DOT____Vtogcov__in_wide[2U] = 
            ((0x1fU & vlTOPp->top__DOT____Vtogcov__in_wide[2U]) 
             | (0x20U & vlTOPp->in_wide[2U]));
    }
    vlTOPp->out_quad = ((IData)(vlTOPp->reset_l) ? 
                        (VL_ULL(0xffffffffff) & (VL_ULL(1) 
                                                 + vlTOPp->in_quad))
                         : VL_ULL(0));
    __Vtemp8[0U] = 1U;
    __Vtemp8[1U] = 0U;
    __Vtemp8[2U] = 0U;
    VL_ADD_W(3, __Vtemp9, __Vtemp8, vlTOPp->in_wide);
    vlTOPp->out_wide[0U] = ((IData)(vlTOPp->reset_l)
                             ? __Vtemp9[0U] : 0U);
    vlTOPp->out_wide[1U] = ((IData)(vlTOPp->reset_l)
                             ? __Vtemp9[1U] : 0U);
    vlTOPp->out_wide[2U] = ((IData)(vlTOPp->reset_l)
                             ? (0x3fU & __Vtemp9[2U])
                             : 0U);
    if ((1U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffeU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (1U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((2U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffdU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (2U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((4U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffbU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (4U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((8U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffff7U & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (8U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffefU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffdfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffbfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffff7fU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x100U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffeffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x100U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x200U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffdffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x200U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x400U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffbffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x400U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x800U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffff7ffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x800U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x1000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffefffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x1000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x2000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffdfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x2000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x4000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffbfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x4000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x8000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffff7fffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x8000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffeffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffdffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffbffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfff7ffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x100000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffefffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x100000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x200000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffdfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x200000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x400000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffbfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x400000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x800000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xff7fffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x800000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x1000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfeffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x1000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x2000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfdffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x2000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x4000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfbffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x4000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x8000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xf7ffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x8000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xefffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xdfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xbfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0x7fffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((1U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffeU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (1U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((2U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffdU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (2U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((4U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffbU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (4U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((8U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffff7U & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (8U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffefU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffdfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffbfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffff7fU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x100U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffeffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x100U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x200U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffdffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x200U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x400U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffbffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x400U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x800U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffff7ffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x800U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x1000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffefffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x1000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x2000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffdfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x2000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x4000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffbfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x4000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x8000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffff7fffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x8000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffeffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffdffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffbffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfff7ffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x100000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffefffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x100000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x200000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffdfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x200000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x400000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffbfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x400000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x800000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xff7fffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x800000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x1000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfeffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x1000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x2000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfdffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x2000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x4000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfbffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x4000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x8000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xf7ffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x8000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xefffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xdfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xbfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0x7fffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((1U & ((IData)(vlTOPp->out_small) ^ vlTOPp->top__DOT____Vtogcov__out_small))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->top__DOT____Vtogcov__out_small = ((2U 
                                                   & (IData)(vlTOPp->top__DOT____Vtogcov__out_small)) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->out_small)));
    }
    if ((2U & ((IData)(vlTOPp->out_small) ^ vlTOPp->top__DOT____Vtogcov__out_small))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->top__DOT____Vtogcov__out_small = ((1U 
                                                   & (IData)(vlTOPp->top__DOT____Vtogcov__out_small)) 
                                                  | (2U 
                                                     & (IData)(vlTOPp->out_small)));
    }
    if ((1U & ((IData)(vlTOPp->out_quad) ^ (IData)(vlTOPp->top__DOT____Vtogcov__out_quad)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffe) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | (IData)((IData)(
                                                                   (1U 
                                                                    & (IData)(vlTOPp->out_quad)))));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 1U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 1U))))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffd) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 1U))))) 
                                                    << 1U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 2U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 2U))))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffffb) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 2U))))) 
                                                    << 2U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 3U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffff7) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 3U))))) 
                                                    << 3U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 4U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 4U))))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffef) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 4U))))) 
                                                    << 4U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 5U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 5U))))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffdf) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 5U))))) 
                                                    << 5U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 6U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 6U))))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffffbf) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 6U))))) 
                                                    << 6U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 7U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 7U))))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffff7f) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 7U))))) 
                                                    << 7U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 8U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 8U))))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffeff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 8U))))) 
                                                    << 8U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 9U)) ^ (IData)(
                                                           (vlTOPp->top__DOT____Vtogcov__out_quad 
                                                            >> 9U))))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffdff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 9U))))) 
                                                    << 9U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xaU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffffbff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xaU))))) 
                                                    << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xbU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffff7ff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xbU))))) 
                                                    << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xcU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffefff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xcU))))) 
                                                    << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xdU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffdfff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xdU))))) 
                                                    << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xeU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffffbfff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xeU))))) 
                                                    << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0xfU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffff7fff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0xfU))))) 
                                                    << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x10U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffeffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x10U))))) 
                                                    << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x11U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffdffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x11U))))) 
                                                    << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x12U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffffbffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x12U))))) 
                                                    << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x13U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffff7ffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x13U))))) 
                                                    << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x14U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffefffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x14U))))) 
                                                    << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x15U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffdfffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x15U))))) 
                                                    << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x16U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffffbfffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x16U))))) 
                                                    << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x17U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffff7fffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x17U))))) 
                                                    << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x18U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffeffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x18U))))) 
                                                    << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x19U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffdffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x19U))))) 
                                                    << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1aU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfffbffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1aU))))) 
                                                    << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1bU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfff7ffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1bU))))) 
                                                    << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1cU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffefffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1cU))))) 
                                                    << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1dU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffdfffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1dU))))) 
                                                    << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1eU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xffbfffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1eU))))) 
                                                    << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x1fU)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xff7fffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x1fU))))) 
                                                    << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x20U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfeffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x20U))))) 
                                                    << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x21U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfdffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x21U))))) 
                                                    << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x22U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xfbffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x22U))))) 
                                                    << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x23U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xf7ffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x23U))))) 
                                                    << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x24U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xefffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x24U))))) 
                                                    << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x25U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xdfffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x25U))))) 
                                                    << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x26U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0xbfffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x26U))))) 
                                                    << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->out_quad >> 0x27U)) 
               ^ (IData)((vlTOPp->top__DOT____Vtogcov__out_quad 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->top__DOT____Vtogcov__out_quad = ((VL_ULL(0x7fffffffff) 
                                                  & vlTOPp->top__DOT____Vtogcov__out_quad) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->out_quad 
                                                                                >> 0x27U))))) 
                                                    << 0x27U));
    }
    if ((1U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (1U & vlTOPp->out_wide[0U]));
    }
    if ((2U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (2U & vlTOPp->out_wide[0U]));
    }
    if ((4U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (4U & vlTOPp->out_wide[0U]));
    }
    if ((8U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (8U & vlTOPp->out_wide[0U]));
    }
    if ((0x10U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10U & vlTOPp->out_wide[0U]));
    }
    if ((0x20U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20U & vlTOPp->out_wide[0U]));
    }
    if ((0x40U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40U & vlTOPp->out_wide[0U]));
    }
    if ((0x80U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80U & vlTOPp->out_wide[0U]));
    }
    if ((0x100U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x100U & vlTOPp->out_wide[0U]));
    }
    if ((0x200U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x200U & vlTOPp->out_wide[0U]));
    }
    if ((0x400U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x400U & vlTOPp->out_wide[0U]));
    }
    if ((0x800U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x800U & vlTOPp->out_wide[0U]));
    }
    if ((0x1000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x1000U & vlTOPp->out_wide[0U]));
    }
    if ((0x2000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x2000U & vlTOPp->out_wide[0U]));
    }
    if ((0x4000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x4000U & vlTOPp->out_wide[0U]));
    }
    if ((0x8000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x8000U & vlTOPp->out_wide[0U]));
    }
    if ((0x10000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10000U & vlTOPp->out_wide[0U]));
    }
    if ((0x20000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20000U & vlTOPp->out_wide[0U]));
    }
    if ((0x40000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40000U & vlTOPp->out_wide[0U]));
    }
    if ((0x80000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80000U & vlTOPp->out_wide[0U]));
    }
    if ((0x100000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x100000U & vlTOPp->out_wide[0U]));
    }
    if ((0x200000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x200000U & vlTOPp->out_wide[0U]));
    }
    if ((0x400000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x400000U & vlTOPp->out_wide[0U]));
    }
    if ((0x800000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x800000U & vlTOPp->out_wide[0U]));
    }
    if ((0x1000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x1000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x2000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x2000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x4000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x4000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x8000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x8000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x10000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x10000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x20000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x20000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x40000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x40000000U & vlTOPp->out_wide[0U]));
    }
    if ((0x80000000U & (vlTOPp->out_wide[0U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[0U]))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->top__DOT____Vtogcov__out_wide[0U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[0U]) 
             | (0x80000000U & vlTOPp->out_wide[0U]));
    }
    if ((1U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffeU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (1U & vlTOPp->out_wide[1U]));
    }
    if ((2U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffdU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (2U & vlTOPp->out_wide[1U]));
    }
    if ((4U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffffbU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (4U & vlTOPp->out_wide[1U]));
    }
    if ((8U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffff7U & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (8U & vlTOPp->out_wide[1U]));
    }
    if ((0x10U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffefU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10U & vlTOPp->out_wide[1U]));
    }
    if ((0x20U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffdfU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20U & vlTOPp->out_wide[1U]));
    }
    if ((0x40U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffffbfU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40U & vlTOPp->out_wide[1U]));
    }
    if ((0x80U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffff7fU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80U & vlTOPp->out_wide[1U]));
    }
    if ((0x100U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffeffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x100U & vlTOPp->out_wide[1U]));
    }
    if ((0x200U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffdffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x200U & vlTOPp->out_wide[1U]));
    }
    if ((0x400U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffffbffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x400U & vlTOPp->out_wide[1U]));
    }
    if ((0x800U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffff7ffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x800U & vlTOPp->out_wide[1U]));
    }
    if ((0x1000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffefffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x1000U & vlTOPp->out_wide[1U]));
    }
    if ((0x2000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffdfffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x2000U & vlTOPp->out_wide[1U]));
    }
    if ((0x4000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffffbfffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x4000U & vlTOPp->out_wide[1U]));
    }
    if ((0x8000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffff7fffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x8000U & vlTOPp->out_wide[1U]));
    }
    if ((0x10000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffeffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10000U & vlTOPp->out_wide[1U]));
    }
    if ((0x20000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffdffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20000U & vlTOPp->out_wide[1U]));
    }
    if ((0x40000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfffbffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40000U & vlTOPp->out_wide[1U]));
    }
    if ((0x80000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfff7ffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80000U & vlTOPp->out_wide[1U]));
    }
    if ((0x100000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffefffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x100000U & vlTOPp->out_wide[1U]));
    }
    if ((0x200000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffdfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x200000U & vlTOPp->out_wide[1U]));
    }
    if ((0x400000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xffbfffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x400000U & vlTOPp->out_wide[1U]));
    }
    if ((0x800000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xff7fffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x800000U & vlTOPp->out_wide[1U]));
    }
    if ((0x1000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfeffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x1000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x2000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfdffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x2000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x4000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xfbffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x4000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x8000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xf7ffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x8000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x10000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xefffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x10000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x20000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xdfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x20000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x40000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0xbfffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x40000000U & vlTOPp->out_wide[1U]));
    }
    if ((0x80000000U & (vlTOPp->out_wide[1U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[1U]))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->top__DOT____Vtogcov__out_wide[1U] = 
            ((0x7fffffffU & vlTOPp->top__DOT____Vtogcov__out_wide[1U]) 
             | (0x80000000U & vlTOPp->out_wide[1U]));
    }
    if ((1U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3eU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (1U & vlTOPp->out_wide[2U]));
    }
    if ((2U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3dU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (2U & vlTOPp->out_wide[2U]));
    }
    if ((4U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x3bU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (4U & vlTOPp->out_wide[2U]));
    }
    if ((8U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x37U & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (8U & vlTOPp->out_wide[2U]));
    }
    if ((0x10U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x2fU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (0x10U & vlTOPp->out_wide[2U]));
    }
    if ((0x20U & (vlTOPp->out_wide[2U] ^ vlTOPp->top__DOT____Vtogcov__out_wide[2U]))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->top__DOT____Vtogcov__out_wide[2U] = 
            ((0x1fU & vlTOPp->top__DOT____Vtogcov__out_wide[2U]) 
             | (0x20U & vlTOPp->out_wide[2U]));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_l) {
        ++(vlSymsp->__Vcoverage[260]);
    }
    if ((1U & (~ (IData)(vlTOPp->reset_l)))) {
        ++(vlSymsp->__Vcoverage[259]);
    }
    vlTOPp->__Vdly__top__DOT__sub__DOT__count_f = vlTOPp->top__DOT__sub__DOT__count_f;
    vlTOPp->__Vdly__top__DOT__sub__DOT__count_f = ((IData)(vlTOPp->reset_l)
                                                    ? 
                                                   ((IData)(1U) 
                                                    + vlTOPp->top__DOT__sub__DOT__count_f)
                                                    : 0U);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG(__Vdly__top__DOT__sub__DOT__count_c,31,0);
    // Body
    __Vdly__top__DOT__sub__DOT__count_c = vlTOPp->top__DOT__sub__DOT__count_c;
    if ((1U & (~ (IData)(vlTOPp->reset_l)))) {
        ++(vlSymsp->__Vcoverage[293]);
    }
    if (vlTOPp->reset_l) {
        ++(vlSymsp->__Vcoverage[295]);
    }
    if ((3U == vlTOPp->top__DOT__sub__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[296]);
    }
    if (vlTOPp->reset_l) {
        if ((3U <= vlTOPp->top__DOT__sub__DOT__count_c)) {
            ++(vlSymsp->__Vcoverage[294]);
        }
    }
    if (vlTOPp->reset_l) {
        __Vdly__top__DOT__sub__DOT__count_c = ((IData)(1U) 
                                               + vlTOPp->top__DOT__sub__DOT__count_c);
        if (VL_UNLIKELY((3U <= vlTOPp->top__DOT__sub__DOT__count_c))) {
            VL_WRITEF("[%0t] fastclk is %0# times faster than clk\n\n",
                      64,VL_TIME_Q(),32,VL_DIV_III(32, vlTOPp->top__DOT__sub__DOT__count_f, vlTOPp->top__DOT__sub__DOT__count_c));
            VL_WRITEF("*-* All Finished *-*\n");
            VL_FINISH_MT("../make_tracing_c/sub.v", 45, "");
        }
    } else {
        __Vdly__top__DOT__sub__DOT__count_c = 0U;
    }
    vlTOPp->top__DOT__sub__DOT__count_c = __Vdly__top__DOT__sub__DOT__count_c;
    if ((1U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffeU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (1U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((2U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffdU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (2U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((4U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffffbU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (4U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((8U & (vlTOPp->top__DOT__sub__DOT__count_c 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffff7U & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (8U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffefU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffdfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffffbfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80U & (vlTOPp->top__DOT__sub__DOT__count_c 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffff7fU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x100U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffeffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x100U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x200U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffdffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x200U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x400U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffffbffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x400U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x800U & (vlTOPp->top__DOT__sub__DOT__count_c 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffff7ffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x800U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x1000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffefffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x1000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x2000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffdfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x2000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x4000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffffbfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x4000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x8000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffff7fffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x8000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffeffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffdffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfffbffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfff7ffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x100000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffefffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x100000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x200000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffdfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x200000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x400000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xffbfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x400000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x800000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xff7fffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x800000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x1000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfeffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x1000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x2000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfdffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x2000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x4000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xfbffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x4000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x8000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xf7ffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x8000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x10000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xefffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x10000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x20000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xdfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x20000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x40000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0xbfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x40000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
    if ((0x80000000U & (vlTOPp->top__DOT__sub__DOT__count_c 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c 
            = ((0x7fffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_c) 
               | (0x80000000U & vlTOPp->top__DOT__sub__DOT__count_c));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sub__DOT__count_f = vlTOPp->__Vdly__top__DOT__sub__DOT__count_f;
    if ((1U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffeU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (1U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((2U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffdU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (2U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((4U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffffbU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (4U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((8U & (vlTOPp->top__DOT__sub__DOT__count_f 
               ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffff7U & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (8U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffefU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffdfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffffbfU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80U & (vlTOPp->top__DOT__sub__DOT__count_f 
                  ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffff7fU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x100U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffeffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x100U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x200U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffdffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x200U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x400U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffffbffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x400U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x800U & (vlTOPp->top__DOT__sub__DOT__count_f 
                   ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffff7ffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x800U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x1000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffefffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x1000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x2000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffdfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x2000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x4000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffffbfffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x4000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x8000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                    ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffff7fffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x8000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffeffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffdffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfffbffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                     ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfff7ffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x100000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffefffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x100000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x200000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffdfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x200000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x400000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xffbfffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x400000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x800000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                      ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xff7fffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x800000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x1000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfeffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x1000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x2000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfdffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x2000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x4000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xfbffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x4000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x8000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                       ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xf7ffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x8000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x10000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xefffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x10000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x20000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xdfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x20000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x40000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0xbfffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x40000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
    if ((0x80000000U & (vlTOPp->top__DOT__sub__DOT__count_f 
                        ^ vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f 
            = ((0x7fffffffU & vlTOPp->top__DOT__sub__DOT____Vtogcov__count_f) 
               | (0x80000000U & vlTOPp->top__DOT__sub__DOT__count_f));
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->fastclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__fastclk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->fastclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__fastclk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__fastclk = vlTOPp->fastclk;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__fastclk = vlTOPp->fastclk;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
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
    if (VL_UNLIKELY((fastclk & 0xfeU))) {
        Verilated::overWidthError("fastclk");}
    if (VL_UNLIKELY((reset_l & 0xfeU))) {
        Verilated::overWidthError("reset_l");}
    if (VL_UNLIKELY((in_small & 0xfcU))) {
        Verilated::overWidthError("in_small");}
    if (VL_UNLIKELY((in_quad & VL_ULL(0)))) {
        Verilated::overWidthError("in_quad");}
    if (VL_UNLIKELY((in_wide[2U] & 0xffffffc0U))) {
        Verilated::overWidthError("in_wide");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    fastclk = VL_RAND_RESET_I(1);
    reset_l = VL_RAND_RESET_I(1);
    out_small = VL_RAND_RESET_I(2);
    out_quad = VL_RAND_RESET_Q(40);
    VL_RAND_RESET_W(70,out_wide);
    in_small = VL_RAND_RESET_I(2);
    in_quad = VL_RAND_RESET_Q(40);
    VL_RAND_RESET_W(70,in_wide);
    top__DOT____Vtogcov__clk = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__fastclk = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__reset_l = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__out_small = VL_RAND_RESET_I(2);
    top__DOT____Vtogcov__out_quad = VL_RAND_RESET_Q(40);
    VL_RAND_RESET_W(70,top__DOT____Vtogcov__out_wide);
    top__DOT____Vtogcov__in_small = VL_RAND_RESET_I(2);
    top__DOT____Vtogcov__in_quad = VL_RAND_RESET_Q(40);
    VL_RAND_RESET_W(70,top__DOT____Vtogcov__in_wide);
    top__DOT__sub__DOT__count_f = VL_RAND_RESET_I(32);
    top__DOT__sub__DOT__count_c = VL_RAND_RESET_I(32);
    top__DOT__sub__DOT____Vtogcov__count_f = VL_RAND_RESET_I(32);
    top__DOT__sub__DOT____Vtogcov__count_c = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__sub__DOT__count_f = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../make_tracing_c/../make_tracing_c/top.v", 13, 0, ".top", "v_toggle/top", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "../make_tracing_c/../make_tracing_c/top.v", 14, 0, ".top", "v_toggle/top", "fastclk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../make_tracing_c/../make_tracing_c/top.v", 15, 0, ".top", "v_toggle/top", "reset_l");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "../make_tracing_c/../make_tracing_c/top.v", 17, 0, ".top", "v_toggle/top", "out_small[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "../make_tracing_c/../make_tracing_c/top.v", 17, 0, ".top", "v_toggle/top", "out_small[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[32]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[33]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[34]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[35]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[36]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[37]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[38]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../make_tracing_c/../make_tracing_c/top.v", 18, 0, ".top", "v_toggle/top", "out_quad[39]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[32]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[33]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[34]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[35]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[36]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[37]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[38]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[39]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[40]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[41]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[42]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[43]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[44]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[45]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[46]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[47]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[48]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[49]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[50]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[51]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[52]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[53]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[54]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[55]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[56]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[57]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[58]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[59]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[60]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[61]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[62]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[63]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[64]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[65]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[111]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[66]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[112]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[67]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[113]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[68]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[114]), first, "../make_tracing_c/../make_tracing_c/top.v", 19, 0, ".top", "v_toggle/top", "out_wide[69]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[115]), first, "../make_tracing_c/../make_tracing_c/top.v", 20, 0, ".top", "v_toggle/top", "in_small[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[116]), first, "../make_tracing_c/../make_tracing_c/top.v", 20, 0, ".top", "v_toggle/top", "in_small[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[117]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[118]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[119]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[120]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[121]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[122]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[123]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[124]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[125]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[126]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[127]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[128]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[130]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[131]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[132]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[134]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[135]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[136]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[137]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[138]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[139]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[140]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[141]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[142]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[143]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[144]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[145]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[146]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[147]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[148]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[149]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[32]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[150]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[33]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[151]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[34]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[152]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[35]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[153]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[36]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[154]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[37]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[155]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[38]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[156]), first, "../make_tracing_c/../make_tracing_c/top.v", 21, 0, ".top", "v_toggle/top", "in_quad[39]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[157]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[158]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[159]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[160]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[161]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[162]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[163]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[164]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[165]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[166]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[167]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[168]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[169]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[170]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[171]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[172]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[173]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[174]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[175]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[176]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[177]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[178]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[179]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[180]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[181]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[182]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[183]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[184]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[185]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[186]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[187]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[188]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[189]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[32]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[190]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[33]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[191]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[34]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[192]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[35]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[193]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[36]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[194]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[37]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[195]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[38]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[196]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[39]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[197]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[40]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[198]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[41]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[199]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[42]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[200]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[43]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[201]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[44]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[202]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[45]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[203]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[46]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[204]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[47]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[205]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[48]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[206]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[49]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[207]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[50]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[208]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[51]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[209]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[52]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[210]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[53]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[211]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[54]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[212]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[55]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[213]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[56]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[214]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[57]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[215]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[58]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[216]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[59]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[217]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[60]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[218]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[61]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[219]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[62]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[220]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[63]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[221]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[64]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[222]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[65]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[223]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[66]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[224]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[67]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[225]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[68]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[226]), first, "../make_tracing_c/../make_tracing_c/top.v", 22, 0, ".top", "v_toggle/top", "in_wide[69]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../make_tracing_c/sub.v", 9, 0, ".top.sub", "v_toggle/sub", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "../make_tracing_c/sub.v", 10, 0, ".top.sub", "v_toggle/sub", "fastclk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../make_tracing_c/sub.v", 11, 0, ".top.sub", "v_toggle/sub", "reset_l");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[227]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[228]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[229]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[230]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[231]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[232]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[233]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[234]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[235]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[236]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[237]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[238]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[239]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[240]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[241]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[242]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[243]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[244]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[245]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[246]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[247]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[248]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[249]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[250]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[251]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[252]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[253]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[254]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[255]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[256]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[257]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[258]), first, "../make_tracing_c/sub.v", 15, 0, ".top.sub", "v_toggle/sub", "count_f[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[259]), first, "../make_tracing_c/sub.v", 17, 0, ".top.sub", "v_line/sub", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[260]), first, "../make_tracing_c/sub.v", 23, 0, ".top.sub", "v_line/sub", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[261]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[262]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[263]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[264]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[265]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[266]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[267]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[268]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[269]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[270]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[271]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[272]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[273]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[274]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[275]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[276]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[277]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[278]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[279]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[280]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[281]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[282]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[283]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[284]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[285]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[286]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[287]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[288]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[289]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[290]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[291]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[292]), first, "../make_tracing_c/sub.v", 29, 0, ".top.sub", "v_toggle/sub", "count_c[31]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[293]), first, "../make_tracing_c/sub.v", 31, 0, ".top.sub", "v_line/sub", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[294]), first, "../make_tracing_c/sub.v", 39, 0, ".top.sub", "v_line/sub", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[295]), first, "../make_tracing_c/sub.v", 37, 0, ".top.sub", "v_line/sub", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[296]), first, "../make_tracing_c/sub.v", 56, 0, ".top.sub", "v_user/sub", "cover");
}
