/**
 * Copyright 2014 Krzysztof Magosa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gtest/gtest.h"
#include "microbe/Tanh.hpp"

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
