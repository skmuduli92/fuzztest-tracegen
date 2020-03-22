#ifndef __COVERAGE_H_DEFINED__
#define __COVERAGE_H_DEFINED__

#include <iostream>
#include <vector>
#include <assert.h>
#include <stdint.h>

class ValueTracker
{
  typedef std::vector<uint32_t> container_t;
private:
  container_t bins;
  unsigned signalWidth;
  uint64_t mask;
  uint64_t signalValue;
public:
  ValueTracker(unsigned numBins, unsigned width ) 
    : bins(numBins, 0)
    , signalWidth(width)
    , signalValue(0)
  {
    assert (width <= 32);
    mask = (1ULL << width) - 1;
  }

  void track(uint32_t value);
  void dump(std::ostream& out) const;
  const uint32_t* data() const { return bins.data(); }
  size_t size() const { return bins.size() ; }

  container_t::iterator begin() { return bins.begin(); }
  container_t::iterator end() { return bins.end(); }
  container_t::const_iterator begin() const { return bins.begin(); }
  container_t::const_iterator end() const { return bins.end(); }
};

#endif // __COVERAGE_H_DEFINED__
