#include <foo/foo.hpp>
#include <gtest/gtest.h>

TEST(FooTest, sumCheck) {
	Foo foo;
	int a = foo.getSum(5,10);
	EXPECT_EQ(a,15);
}

TEST(FooTest, sumCheck2) {
	Foo foo;
	int a = foo.getSum(-4,4);
	EXPECT_EQ(a, 0);
}
