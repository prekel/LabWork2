#include <gtest/gtest.h>
extern "C" {
#include "../LabWork.Lib/functions.h"
}

TEST(TestCaseName, SerialResistTest1) {
	double d[3] = { 1, 2, 3 };
	ASSERT_EQ(6, serial_resist(3, d));
}