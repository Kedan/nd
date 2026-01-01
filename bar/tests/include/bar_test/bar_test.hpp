#pragma once

#include <bar/bar.hpp>
#include <gtest/gtest.h>

class BarTest : public testing::Test {
	protected:
		Bar bar;

		int a = 2;
		int b = 5;
		int c = 10;
};
