#include <gtest/gtest.h>

#include "formula.h"
#include "parse_util.h"
#include "trace.h"

using namespace HyperPLTL;

void randomizeVecData(std::vector<uint32_t>& vec) {
  for (uint32_t& data : vec) {
    data = rand() % std::numeric_limits<uint32_t>::max();
  }
}

void printVec(std::vector<uint32_t>& vec) {
  for (uint32_t& data : vec) {
    std::cout << data << ", ";
  }
  std::cout << std::endl;
}

void resetData(std::vector<uint32_t>& vec) {
  for (uint32_t& data : vec) {
    data = 0;
  }
}

// guarantees the new random vector is different than
// the current random vector provided as input
void newRandomVecData(std::vector<uint32_t>& vec) {
  std::vector<uint32_t> oldVecd(vec);
  while (oldVecd == vec) {
    for (uint32_t& data : vec) {
      data = rand() % std::numeric_limits<uint32_t>::max();
    }
  }
}

TEST(PropertyLibTest, ValidTracePropTermArray_Test1) {
  std::string propstr = "(G (EQ bytes[4]))";
  PVarMap varmap(new VarMap());
  PHyperProp property = parse_formula(propstr, varmap);

  PTrace trace1(new Trace(0, 1));
  PTrace trace2(new Trace(0, 1));
  TraceList tracelist({trace1, trace2});
  varinfo_t varinfo = property->getArrayVarInfo("bytes");

  std::vector<uint32_t> arrval(varinfo.second);

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    if (rand() % 2) {
      randomizeVecData(arrval);
    } else {
      resetData(arrval);
    }
    trace1->updateTermValue(varinfo.first, cycle, arrval);
    trace2->updateTermValue(varinfo.first, cycle, arrval);

    result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, ValidTracePropTermArray_Test1_Fail) {
  std::string propstr = "(G (EQ bytes[4]))";
  PVarMap varmap(new VarMap());
  PHyperProp property = parse_formula(propstr, varmap);

  PTrace trace1(new Trace(0, 1));
  PTrace trace2(new Trace(0, 1));
  TraceList tracelist({trace1, trace2});
  varinfo_t varinfo = property->getArrayVarInfo("bytes");

  std::vector<uint32_t> arrval(varinfo.second);

  bool result = true;
  unsigned traceLength = rand() % 20 + 20;
  unsigned faultIdx = rand() % traceLength;

  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    if (rand() % 2) {
      randomizeVecData(arrval);
    }

    trace1->updateTermValue(varinfo.first, cycle, arrval);

    if (faultIdx == cycle)
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    else {
      newRandomVecData(arrval);
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    }
    result = property->eval(cycle, tracelist);
  }
  EXPECT_FALSE(result);
}

TEST(PropertyLibTest, ValidTracePropTermArray_Test2) {
  std::string propstr = "(IMPLIES (EQ x) (EQ bytes[4]))";
  PVarMap varmap(new VarMap());
  PHyperProp property = parse_formula(propstr, varmap);

  PTrace trace1(new Trace(0, 2));
  PTrace trace2(new Trace(0, 2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  unsigned xIdx = property->getVarId("x");
  varinfo_t varinfo = property->getArrayVarInfo("bytes");
  std::vector<uint32_t> arrval(varinfo.second);

  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % std::numeric_limits<unsigned>::max();

    if (rand() % 2) {
      trace1->updateTermValue(xIdx, cycle, xvalue);
      trace2->updateTermValue(xIdx, cycle, xvalue);
      randomizeVecData(arrval);
      trace1->updateTermValue(varinfo.first, cycle, arrval);
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    } else {
      trace1->updateTermValue(xIdx, cycle, xvalue);
      trace2->updateTermValue(xIdx, cycle, !xvalue);
      randomizeVecData(arrval);
      trace1->updateTermValue(varinfo.first, cycle, arrval);
      if (rand() % 2) randomizeVecData(arrval);
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    }

    result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, ValidTracePropTermArray_Test2_Fail) {
  std::string propstr = "(IMPLIES (EQ x) (EQ bytes[4]))";
  PVarMap varmap(new VarMap());
  PHyperProp property = parse_formula(propstr, varmap);

  PTrace trace1(new Trace(0, 2));
  PTrace trace2(new Trace(0, 2));
  TraceList tracelist({trace1, trace2});

  bool result = true;
  unsigned traceLength = rand() % 20 + 20;

  unsigned xIdx = property->getVarId("x");
  varinfo_t varinfo = property->getArrayVarInfo("bytes");
  std::vector<uint32_t> arrval(varinfo.second);

  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % std::numeric_limits<unsigned>::max();

    if (rand() % 2) {
      trace1->updateTermValue(xIdx, cycle, xvalue);
      trace2->updateTermValue(xIdx, cycle, xvalue);
      randomizeVecData(arrval);
      trace1->updateTermValue(varinfo.first, cycle, arrval);
      newRandomVecData(arrval);
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    } else {
      trace1->updateTermValue(xIdx, cycle, xvalue);
      trace2->updateTermValue(xIdx, cycle, !xvalue);
      randomizeVecData(arrval);
      trace1->updateTermValue(varinfo.first, cycle, arrval);
      if (rand() % 2) randomizeVecData(arrval);
      trace2->updateTermValue(varinfo.first, cycle, arrval);
    }

    result = property->eval(cycle, tracelist);
  }

  EXPECT_FALSE(result);
}
