// DESCRIPTION: Verilator generated C++
#include "Vsecret_impl.h"
#include "verilated_dpi.h"

#include <cstdio>
#include <cstdlib>

class Vsecret_impl_container: public Vsecret_impl {
  public:
    long long m_seqnum;
    Vsecret_impl_container(const char* scopep__V):
    Vsecret_impl(scopep__V) {}
};

extern "C" {
    
    void verilated_secret_protectlib_check_hash (int protectlib_hash__V) {
        int expected_hash__V =
        1254736918;
        if (protectlib_hash__V != expected_hash__V) {
            fprintf(stderr, "%%Error: cannot use verilated_secret library, Verliog (%u) and library (%u) hash values do not agree\n", protectlib_hash__V, expected_hash__V);
            exit(EXIT_FAILURE);
        }
    }
    
    void* verilated_secret_protectlib_create (const char* scopep__V) {
        Vsecret_impl_container* handlep__V = new Vsecret_impl_container(scopep__V);
        return handlep__V;
    }
    
    long long verilated_secret_protectlib_combo_update (
        void* vhandlep__V
        , const svLogicVecVal* a
        , const svLogicVecVal* b
        , svLogicVecVal* x
    )
    {
        Vsecret_impl_container* handlep__V = static_cast<Vsecret_impl_container*>(vhandlep__V);
        handlep__V->a = VL_SET_I_SVLV(a);
        handlep__V->b = VL_SET_I_SVLV(b);
        handlep__V->eval();
        VL_SET_SVLV_I(32, x, handlep__V->x);
        return handlep__V->m_seqnum++;
    }
    
    long long verilated_secret_protectlib_seq_update (
        void* vhandlep__V
        , svLogicVecVal* x
        , unsigned char clk
    )
    {
        Vsecret_impl_container* handlep__V = static_cast<Vsecret_impl_container*>(vhandlep__V);
        handlep__V->clk = clk;
        handlep__V->eval();
        VL_SET_SVLV_I(32, x, handlep__V->x);
        return handlep__V->m_seqnum++;
    }
    
    void verilated_secret_protectlib_combo_ignore (
        void* vhandlep__V
        , const svLogicVecVal* a
        , const svLogicVecVal* b
    )
    { }
    
    void verilated_secret_protectlib_final (void* vhandlep__V) {
        Vsecret_impl_container* handlep__V = static_cast<Vsecret_impl_container*>(vhandlep__V);
        handlep__V->final();
        delete handlep__V;
    }
    
}
