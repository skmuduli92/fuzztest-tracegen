
#include <tracegen.h>

void TraceGen::recordIntSignal(std::string const& sname, uint32_t traceId, uint64_t time,
                               int64_t value) {

  if (time >= 20)
    int_facts[intvar2id[sname]] << traceId << "\t" << time - 20 << "\t" << value
                                << std::endl;
}
