#include "Vtop_instr.h"
#include <iostream>
#include <ctime>
#include "ModelMetaClass.h"


void ModelMetaClass::inputInterface() {
	srand(time(NULL));
	std::cin >> top->clk;
	std::cin >> top->rst;
}
