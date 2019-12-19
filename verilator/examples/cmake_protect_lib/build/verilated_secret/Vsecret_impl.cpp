// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsecret_impl.h for the primary calling header

#include "Vsecret_impl.h"
#include "Vsecret_impl_PSfoAy.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsecret_impl) {
    Vsecret_impl_PSfoAy* __restrict vlSymsp = __VlSymsp = new Vsecret_impl_PSfoAy(this, name());
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    PSNLLT();
}

void Vsecret_impl::PSz5AI(Vsecret_impl_PSfoAy* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsecret_impl::~Vsecret_impl() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsecret_impl::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsecret_impl::eval\n"); );
    Vsecret_impl_PSfoAy* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    PSkged();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) PSW5Ub(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        PSc1JR(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSrKVU(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PS2uH0", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSrKVU(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsecret_impl::PSW5Ub(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    PSguha(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        PSfsMM(vlSymsp);
        PSc1JR(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSrKVU(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PS2uH0", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSrKVU(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vsecret_impl::PSlNA1(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSlNA1\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("%Nsecret_impl: initialized\n",vlSymsp->name());
    vlTOPp->PSLcz0 = 0U;
}

VL_INLINE_OPT void Vsecret_impl::PS63Ll(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PS63Ll\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint all: 
    VL_SIG(PSzBK2,31,0);
    // Body
    PSzBK2 = vlTOPp->PSLcz0;
    PSzBK2 = (vlTOPp->PSLcz0 + vlTOPp->a);
    vlTOPp->x = ((0xaU < vlTOPp->PSLcz0) ? vlTOPp->b
                  : ((IData)(9U) + (vlTOPp->a + vlTOPp->b)));
    vlTOPp->PSLcz0 = PSzBK2;
}

void Vsecret_impl::PSc1JR(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSc1JR\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->PSWqdZ)))) {
        vlTOPp->PS63Ll(vlSymsp);
    }
    // Final
    vlTOPp->PSWqdZ = vlTOPp->clk;
}

void Vsecret_impl::PSguha(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSguha\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PSlNA1(vlSymsp);
    vlTOPp->PSWqdZ = vlTOPp->clk;
}

void Vsecret_impl::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::final\n"); );
    // Variables
    Vsecret_impl_PSfoAy* __restrict vlSymsp = this->__VlSymsp;
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsecret_impl::PSfsMM(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSfsMM\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vsecret_impl::PSrKVU(Vsecret_impl_PSfoAy* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSrKVU\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsecret_impl::PSkged() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSkged\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif // VL_DEBUG

void Vsecret_impl::PSNLLT() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSNLLT\n"); );
    // Body
    a = VL_RAND_RESET_I(32);
    b = VL_RAND_RESET_I(32);
    x = VL_RAND_RESET_I(32);
    clk = VL_RAND_RESET_I(1);
    PSLcz0 = VL_RAND_RESET_I(32);
}
