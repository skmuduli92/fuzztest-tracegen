#include "coverage.h"
#include <iomanip>

void ValueTracker::track(uint32_t value)
{
  signalValue = (signalValue << 32) | (value & mask);
  bins[signalValue % bins.size()] += 1;
}

void ValueTracker::dump(std::ostream& out) const
{
  for(unsigned i=0; i != bins.size(); i++) {
    if(bins[i] != 0) {
      out << std::setw(6) << i << ": " << std::setw(6) << bins[i] << std::endl;
    }
  }
}
