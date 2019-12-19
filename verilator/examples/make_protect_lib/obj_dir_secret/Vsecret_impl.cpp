// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsecret_impl.h for the primary calling header

#include "Vsecret_impl.h"
#include "Vsecret_impl_PSUCik.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsecret_impl) {
    Vsecret_impl_PSUCik* __restrict vlSymsp = __VlSymsp = new Vsecret_impl_PSUCik(this, name());
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    PSw2N2();
}

void Vsecret_impl::PSroGv(Vsecret_impl_PSUCik* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsecret_impl::~Vsecret_impl() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsecret_impl::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsecret_impl::eval\n"); );
    Vsecret_impl_PSUCik* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    PSAFl4();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) PSSjPq(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        PSNoq6(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSA8cC(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PSAHNy", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSA8cC(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsecret_impl::PSSjPq(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    PSyVpu(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        PSD5AJ(vlSymsp);
        PSNoq6(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSA8cC(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PSAHNy", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSA8cC(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vsecret_impl::PSDi4J(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSDi4J\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("%Nsecret_impl: initialized\n",vlSymsp->name());
    vlTOPp->PSQtCi = 0U;
}

VL_INLINE_OPT void Vsecret_impl::PS67EA(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PS67EA\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG(PSgBiU,31,0);
    // Body
    PSgBiU = vlTOPp->PSQtCi;
    PSgBiU = (vlTOPp->PSQtCi + vlTOPp->a);
    vlTOPp->x = ((0xaU < vlTOPp->PSQtCi) ? vlTOPp->b
                  : ((IData)(9U) + (vlTOPp->a + vlTOPp->b)));
    vlTOPp->PSQtCi = PSgBiU;
}

void Vsecret_impl::PSNoq6(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSNoq6\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->PSdN9F)))) {
        vlTOPp->PS67EA(vlSymsp);
    }
    // Final
    vlTOPp->PSdN9F = vlTOPp->clk;
}

void Vsecret_impl::PSyVpu(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSyVpu\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PSDi4J(vlSymsp);
    vlTOPp->PSdN9F = vlTOPp->clk;
}

void Vsecret_impl::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::final\n"); );
    // Variables
    Vsecret_impl_PSUCik* __restrict vlSymsp = this->__VlSymsp;
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsecret_impl::PSD5AJ(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSD5AJ\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vsecret_impl::PSA8cC(Vsecret_impl_PSUCik* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSA8cC\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsecret_impl::PSAFl4() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSAFl4\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif // VL_DEBUG

void Vsecret_impl::PSw2N2() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSw2N2\n"); );
    // Body
    a = VL_RAND_RESET_I(32);
    b = VL_RAND_RESET_I(32);
    x = VL_RAND_RESET_I(32);
    clk = VL_RAND_RESET_I(1);
    PSQtCi = VL_RAND_RESET_I(32);
}
