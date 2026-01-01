#pragma once

#include <foo/foo.hpp>
#include <gtest/gtest.h>

class FooTest : public  testing::Test {
	protected:
		Foo foo;
		int m_A = 1;
		int m_B = 3;
		int m_C = -3;
};
