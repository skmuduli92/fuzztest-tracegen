// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+3,"clk",-1);
        vcdp->declBit(c+4,"fastclk",-1);
        vcdp->declBit(c+5,"reset_l",-1);
        vcdp->declBus(c+6,"out_small",-1,1,0);
        vcdp->declQuad(c+7,"out_quad",-1,39,0);
        vcdp->declArray(c+9,"out_wide",-1,69,0);
        vcdp->declBus(c+12,"in_small",-1,1,0);
        vcdp->declQuad(c+13,"in_quad",-1,39,0);
        vcdp->declArray(c+15,"in_wide",-1,69,0);
        vcdp->declBit(c+3,"top clk",-1);
        vcdp->declBit(c+4,"top fastclk",-1);
        vcdp->declBit(c+5,"top reset_l",-1);
        vcdp->declBus(c+6,"top out_small",-1,1,0);
        vcdp->declQuad(c+7,"top out_quad",-1,39,0);
        vcdp->declArray(c+9,"top out_wide",-1,69,0);
        vcdp->declBus(c+12,"top in_small",-1,1,0);
        vcdp->declQuad(c+13,"top in_quad",-1,39,0);
        vcdp->declArray(c+15,"top in_wide",-1,69,0);
        vcdp->declBit(c+3,"top sub clk",-1);
        vcdp->declBit(c+4,"top sub fastclk",-1);
        vcdp->declBit(c+5,"top sub reset_l",-1);
        vcdp->declBus(c+2,"top sub count_f",-1,31,0);
        vcdp->declBus(c+1,"top sub count_c",-1,31,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->top__DOT__sub__DOT__count_c),32);
        vcdp->fullBus(c+2,(vlTOPp->top__DOT__sub__DOT__count_f),32);
        vcdp->fullBit(c+3,(vlTOPp->clk));
        vcdp->fullBit(c+4,(vlTOPp->fastclk));
        vcdp->fullBit(c+5,(vlTOPp->reset_l));
        vcdp->fullBus(c+6,(vlTOPp->out_small),2);
        vcdp->fullQuad(c+7,(vlTOPp->out_quad),40);
        vcdp->fullArray(c+9,(vlTOPp->out_wide),70);
        vcdp->fullBus(c+12,(vlTOPp->in_small),2);
        vcdp->fullQuad(c+13,(vlTOPp->in_quad),40);
        vcdp->fullArray(c+15,(vlTOPp->in_wide),70);
    }
}
