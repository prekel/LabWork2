#include <gtest/gtest.h>
#include <string>

extern "C" {
#include "../LabWork2.Lib/functions.h"
}

TEST(TestCaseName, SerialResistTest1) {
	double d[3] = {1, 2, 3};
	ASSERT_DOUBLE_EQ(6, serial_resist(3, d));
}

TEST(TestCaseName, ParallelResistTest1) {
	double d[3] = {1, 2, 3};
	ASSERT_DOUBLE_EQ(1 / (1 + 1.0 / 2 + 1.0 / 3), parallel_resist(3, d));
}

TEST(TestCaseName, ChekerNTest) {
	ASSERT_EQ(false, checkerN(0));
	ASSERT_EQ(false, checkerN(-87));
	ASSERT_EQ(true, checkerN(6));
}

TEST(TestCaseName, ChekerResistTest) {
	ASSERT_EQ(false, checkerResist(0));
	ASSERT_EQ(true, checkerResist(0.54));
	ASSERT_EQ(false, checkerResist(-87));
	ASSERT_EQ(true, checkerResist(6));
}

TEST(TestCaseName, SplitTest1) {
	char *str1 = "qwerty";
	char *str2 = "zxc vbn";
	char *str3 = "try split this";
	char **splitted;

	int c1 = split(str1, ' ', &splitted);
	ASSERT_EQ(1, c1);
	ASSERT_STREQ("qwerty", splitted[0]);

	int c2 = split(str2, ' ', &splitted);
	ASSERT_EQ(2, c2);
	ASSERT_STREQ("zxc", splitted[0]);
	ASSERT_STREQ("vbn", splitted[1]);

	int c3 = split(str3, ' ', &splitted);
	ASSERT_EQ(3, c3);
	ASSERT_STREQ("try", splitted[0]);
	ASSERT_STREQ("split", splitted[1]);
	ASSERT_STREQ("this", splitted[2]);
}
