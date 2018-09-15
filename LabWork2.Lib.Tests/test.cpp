#include <gtest/gtest.h>
extern "C" {
#include "../LabWork2.Lib/functions.h"
}

TEST(TestCaseName, SerialResistTest1) {
	double d[3] = { 1, 2, 3 };
	ASSERT_DOUBLE_EQ(6, serial_resist(3, d));
}

TEST(TestCaseName, ParallelResistTest1) {
	double d[3] = { 1, 2, 3 };
	ASSERT_DOUBLE_EQ(1 / (1 + 1.0 / 2 + 1.0 / 3), parallel_resist(3, d));
}

TEST(TestCaseName, ChekerNTest){
	ASSERT_EQ(false, checkerN(0));
	ASSERT_EQ(false, checkerN(-87));
	ASSERT_EQ(true, checkerN(6));
}

TEST(TestCaseName, ChekerResistTest){
	ASSERT_EQ(false, checkerResist(0));
	ASSERT_EQ(true, checkerResist(0.54));
	ASSERT_EQ(false, checkerResist(-87));
	ASSERT_EQ(true, checkerResist(6));
}