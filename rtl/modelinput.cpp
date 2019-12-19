#include "Vtop_instr.h"
#include <iostream>
#include <ctime>
#include "ModelMetaClass.h"
#include "AFLSim.h"


void AFLSim::applyInput() {

	top->clk = (top->clk ^ 1);
	scanf("%hhu", (CData *)&(top->rst));
	top->rst = top->rst& (1 << 1);
}


void ModelMetaClass::apply_input(const int8_t* input_stream) {

	top->clk = (top->clk ^ 1);
	readData<CData>(input_stream, &top->rst,0);
}


void ModelMetaClass::genRandomInput() {
	srand(time(NULL));
	top->clk = gen_cdata(0);
	top->rst = gen_cdata(0);
}


void ModelMetaClass::saveRandomInput() {
	srand(time(NULL));
	static unsigned fno = 0;
	while (fno < 1) {
		std::string fname = "input/" + std::to_string(fno++) + ".txt";
		std::ofstream ofs(fname.c_str(), std::ofstream::out);
		ofs << (uint64_t)gen_cdata(0) << std::endl;
		ofs << (uint64_t)gen_cdata(0) << std::endl;
		ofs.close();
	}
}


void ModelMetaClass::printInputVals() {
	std::cout << "clk : " << (uint64_t) top->clk << std::endl;
	std::cout << "rst : " << (uint64_t) top->rst << std::endl;
}


void ModelMetaClass::printOutputVals() {
std::cout << "======== OUTPORT VALUES ======" << std::endl;
std::cout << "==================" << std::endl;
}
