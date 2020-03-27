#include <trace.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
