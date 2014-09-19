#include "CppUTest/CommandLineTestRunner.h"
#include "Sigmoid.h"

microbe::Sigmoid *sigmoid;

TEST_GROUP(Sigmoid)
{
	void setup()
	{
		sigmoid = new microbe::Sigmoid();
	}

	void teardown()
	{
		delete sigmoid;
	}
};

TEST(Sigmoid, Limits)
{
	DOUBLES_EQUAL(1.0, sigmoid->getUpperLimit(), 0.00001);
	DOUBLES_EQUAL(0.0, sigmoid->getLowerLimit(), 0.00001);
};

TEST(Sigmoid, Function)
{
	DOUBLES_EQUAL(0.50000, sigmoid->function(0.00000), 0.00001);
	DOUBLES_EQUAL(0.62245, sigmoid->function(0.50000), 0.00001);
	DOUBLES_EQUAL(0.73105, sigmoid->function(1.00000), 0.00001);
};

TEST(Sigmoid, Derivative)
{
	DOUBLES_EQUAL(0.25000, sigmoid->derivative(0.50000), 0.00001);
	DOUBLES_EQUAL(0.23500, sigmoid->derivative(0.62245), 0.00001);
	DOUBLES_EQUAL(0.19661, sigmoid->derivative(0.73105), 0.00001);
};

int main(int argc, char **argv)
{
   return CommandLineTestRunner::RunAllTests(argc, argv);
}
