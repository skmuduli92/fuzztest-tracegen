// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to insure
// the C functions match the expectations of the DPI imports.

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    
    // DPI IMPORTS
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:14
    extern void verilated_secret_protectlib_check_hash(int protectlib_hash___05FV);
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:38
    extern void verilated_secret_protectlib_combo_ignore(void* handle___05FV, const svLogicVecVal* a, const svLogicVecVal* b);
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:22
    extern long long verilated_secret_protectlib_combo_update(void* handle___05FV, const svLogicVecVal* a, const svLogicVecVal* b, svLogicVecVal* x);
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:19
    extern void* verilated_secret_protectlib_create(const char* scope___05FV);
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:45
    extern void verilated_secret_protectlib_final(void* handle___05FV);
    // DPI import at /home/sujit/Tools/DeltaSigmaSoC/verilator/examples/cmake_protect_lib/build/verilated_secret/verilated_secret.sv:30
    extern long long verilated_secret_protectlib_seq_update(void* handle___05FV, svLogicVecVal* x, unsigned char clk);
    
#ifdef __cplusplus
}
#endif
