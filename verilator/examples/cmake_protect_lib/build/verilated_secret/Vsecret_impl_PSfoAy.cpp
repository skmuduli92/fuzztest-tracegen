// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsecret_impl_PSfoAy.h"
#include "Vsecret_impl.h"



// FUNCTIONS
Vsecret_impl_PSfoAy::Vsecret_impl_PSfoAy(Vsecret_impl* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->PSz5AI(this, true);
    // Setup scopes
    PS8V5U.configure(this, name(), "PS4TIj", "PS4TIj", VerilatedScope::SCOPE_OTHER);
}
