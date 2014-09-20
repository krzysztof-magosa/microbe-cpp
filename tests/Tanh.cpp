#include "gtest/gtest.h"
#include "Tanh.h"

TEST(Tanh, Limits)
{
	microbe::Tanh tanh;
	EXPECT_NEAR( 1.0, tanh.getUpperLimit(), 0.00001);
	EXPECT_NEAR(-1.0, tanh.getLowerLimit(), 0.00001);
};

TEST(Tanh, Function)
{
	microbe::Tanh tanh;
	EXPECT_NEAR(-0.76159, tanh.function(-1.00000), 0.00001);
	EXPECT_NEAR( 0.00000, tanh.function( 0.00000), 0.00001);
	EXPECT_NEAR( 0.76159, tanh.function( 1.00000), 0.00001);
};

TEST(Tanh, Derivative)
{
	microbe::Tanh tanh;
	EXPECT_NEAR(0.41998, tanh.derivative(-0.76159), 0.00001);
	EXPECT_NEAR(1.00000, tanh.derivative( 0.00000), 0.00001);
	EXPECT_NEAR(0.41998, tanh.derivative( 0.76159), 0.00001);
};
