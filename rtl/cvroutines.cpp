#include "ModelMetaClass.h"
#include "AFLSim.h"
#include <iostream>

void ModelMetaClass::init_cvcount() {
	coverage_count = {{"_cvpt_0", 0},{"_cvpt_1", 0},{"_cvpt_2", 0},{"_cvpt_3", 0},{"_cvpt_4", 0},{"_cvpt_5", 0},{"_cvpt_6", 0},{"_cvpt_7", 0},{"_cvpt_8", 0}};
}

void ModelMetaClass::init_cvptvalues() {
	cvpoint_val = {{"_cvpt_0", 0},{"_cvpt_1", 0},{"_cvpt_2", 0},{"_cvpt_3", 0},{"_cvpt_4", 0},{"_cvpt_5", 0},{"_cvpt_6", 0},{"_cvpt_7", 0},{"_cvpt_8", 0}};
}

void ModelMetaClass::init_cvptrmap() {
	cvptr_map = {{"_cvpt_0", &(top->_cvpt_0)},{"_cvpt_1", &(top->_cvpt_1)},{"_cvpt_2", &(top->_cvpt_2)},{"_cvpt_3", &(top->_cvpt_3)},{"_cvpt_4", &(top->_cvpt_4)},{"_cvpt_5", &(top->_cvpt_5)},{"_cvpt_6", &(top->_cvpt_6)},{"_cvpt_7", &(top->_cvpt_7)},{"_cvpt_8", &(top->_cvpt_8)}};
}


void AFLSim::readCoverage() {
	if ( 1 == top->_cvpt_0) coverageData[0] += 1;
	if ( 1 == top->_cvpt_1) coverageData[1] += 1;
	if ( 1 == top->_cvpt_2) coverageData[2] += 1;
	if ( 1 == top->_cvpt_3) coverageData[3] += 1;
	if ( 1 == top->_cvpt_4) coverageData[4] += 1;
	if ( 1 == top->_cvpt_5) coverageData[5] += 1;
	if ( 1 == top->_cvpt_6) coverageData[6] += 1;
	if ( 1 == top->_cvpt_7) coverageData[7] += 1;
	if ( 1 == top->_cvpt_8) coverageData[8] += 1;
}
