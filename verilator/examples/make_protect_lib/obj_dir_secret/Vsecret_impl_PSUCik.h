// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _Vsecret_impl_PSUCik_H_
#define _Vsecret_impl_PSUCik_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vsecret_impl.h"

// SYMS CLASS
class Vsecret_impl_PSUCik : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vsecret_impl*                  TOPp;
    
    // SCOPE NAMES
    VerilatedScope PS6csb;
    
    // CREATORS
    Vsecret_impl_PSUCik(Vsecret_impl* topp, const char* namep);
    ~Vsecret_impl_PSUCik() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
