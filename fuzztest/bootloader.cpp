#include <iostream>
#include <verilated.h>
#include "secureboot.h"
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include <memory>
#include <string>

// required for afl
// static int fid = 0;

int main() {
    // create top module
    std::unique_ptr<Voc8051_tb> top = std::make_unique<Voc8051_tb>();

    // filenames
    std::string romfile("../rom/secureboot.dat");
    std::string imgfile("../rom/prog.hex");
    run(top.get(), NoTamper, romfile, imgfile);

    return 0;
}
