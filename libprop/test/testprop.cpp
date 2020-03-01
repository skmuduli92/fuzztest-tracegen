#include <iostream>
#include <trace.h>
#include <formula.h>

void test1()
{
  using namespace HyperPLTL;
  using namespace std;

  PVarMap varmap(new VarMap());
  unsigned idx_v = varmap->addVar("x");
  PTerm v(new Variable(varmap, idx_v));

  cout << *v << endl;
}

int main(int argc, char* argv[])
{
  test1();
  return 0;
}
