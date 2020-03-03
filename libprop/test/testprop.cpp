#include <iostream>
#include <iomanip>
#include <trace.h>
#include <formula.h>

#include <cstdlib>

std::pair<PTrace, PTrace> createSatTraces1(unsigned xIndex, unsigned yIndex)
{
  using namespace std;

  assert (xIndex == 0);
  assert (yIndex == 1);
  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));

  unsigned traceLen = rand() % 20 + 20;
  unsigned xValue = rand() % 65536;
  unsigned yValue = rand() % 65536;
  trace1->updateTermValue(0, 0, xValue);
  trace2->updateTermValue(0, 0, xValue);
  trace1->updateTermValue(1, 0, yValue);
  trace2->updateTermValue(1, 0, yValue);
  for (unsigned cyc=1; cyc != traceLen; cyc++) {
    if (rand() % 3 == 0) {
      xValue = rand() % 65536;
      trace1->updateTermValue(0, cyc, xValue);
      trace2->updateTermValue(0, cyc, xValue);
    }
    if (rand() % 3 == 1) {
      yValue = rand() % 65536;
      trace1->updateTermValue(1, cyc, yValue);
      trace2->updateTermValue(1, cyc, yValue);
    }
  }

  for (unsigned cyc=0; cyc != traceLen; cyc++) {
    cout << setw(5) << trace1->termValueAt(0, cyc) << "/" <<
            setw(5) << trace2->termValueAt(0, cyc) << ";" <<
            setw(5) << trace1->termValueAt(1, cyc) << "/" <<
            setw(5) << trace2->termValueAt(1, cyc) << ";" << endl;
  }

  return pair(trace1, trace2);
}

void test1()
{
  using namespace HyperPLTL;
  using namespace std;

  // Formula: G(x.1 = x.2) => G(y.1 = y.2)
  PVarMap varmap(new VarMap());
  // x
  unsigned xIndex = varmap->addVar("x");
  PTerm x(new TermVar(varmap, xIndex));
  // y
  unsigned yIndex = varmap->addVar("y");
  PTerm y(new TermVar(varmap, yIndex));
  // (eq x)
  PHyperProp eqX(new Equal(varmap, x));
  // (eq y)
  PHyperProp eqY(new Equal(varmap, y));
  // (G (eq x))
  PHyperProp GeqX(new Always(varmap, eqX));
  // (G (eq y))
  PHyperProp GeqY(new Always(varmap, eqY));
  // (G (eq x)) => (G (eq y))
  PHyperProp F(new Implies(varmap, GeqX, GeqY));
  cout << "formula: "; F->display(cout); cout << endl;

  auto traces = createSatTraces1(xIndex, yIndex);
}

int main(int argc, char* argv[])
{
  test1();
  return 0;
}
