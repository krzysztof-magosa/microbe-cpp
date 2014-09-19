#include "CppUTest/CommandLineTestRunner.h"
#include "Tanh.h"

microbe::Tanh *tanh;

TEST_GROUP(Tanh)
{
	void setup()
	{
		tanh = new microbe::Tanh();
	}

	void teardown()
	{
		delete tanh;
	}
};

TEST(Tanh, Limits)
{
	DOUBLES_EQUAL( 1.0, tanh->getUpperLimit(), 0.00001);
	DOUBLES_EQUAL(-1.0, tanh->getLowerLimit(), 0.00001);
};

TEST(Tanh, Function)
{
	DOUBLES_EQUAL(-0.76159, tanh->function(-1.00000), 0.00001);
	DOUBLES_EQUAL( 0.00000, tanh->function( 0.00000), 0.00001);
	DOUBLES_EQUAL( 0.76159, tanh->function( 1.00000), 0.00001);
};

TEST(Tanh, Derivative)
{
	DOUBLES_EQUAL(0.41998, tanh->derivative(-0.76159), 0.00001);
	DOUBLES_EQUAL(1.00000, tanh->derivative( 0.00000), 0.00001);
	DOUBLES_EQUAL(0.41998, tanh->derivative( 0.76159), 0.00001);
};

int main(int argc, char **argv)
{
   return CommandLineTestRunner::RunAllTests(argc, argv);
}
