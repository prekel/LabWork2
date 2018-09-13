#include <gtest/gtest.h>
//extern "C" {
#include "../LabWork2.Lib/functions.h"
//}

TEST(TestCaseName, SerialResistTest1) {
	double d[3] = { 1, 2, 3 };
	ASSERT_DOUBLE_EQ(6, serial_resist(3, d));
}

TEST(TestCaseName, ParallelResistTest1) {
	double d[3] = { 1, 2, 3 };
	ASSERT_DOUBLE_EQ(1 / (1 + 1.0 / 2 + 1.0 / 3), parallel_resist(3, d));
}