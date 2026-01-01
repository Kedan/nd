#include <bar/bar.hpp>
#include <gtest/gtest.h>

TEST(BarTest, getMultTest) {
	Bar bar;
	int a = bar.getMult(2,3);
	EXPECT_EQ(a, 6);
}
