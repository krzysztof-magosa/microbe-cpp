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
#include "Neuron.h"
#include "Sigmoid.h"

TEST(NeuronTest, Type)
{
	microbe::Neuron neuron;
	ASSERT_EQ(microbe::Neuron::NeuronType::Plain, neuron.getType());
}

TEST(NeuronTest, Function)
{
	microbe::Function *sigmoid1 = new microbe::Sigmoid();
	microbe::Function *sigmoid2 = new microbe::Sigmoid();

	microbe::Neuron neuron;
	neuron.setFunction(sigmoid1);

	ASSERT_EQ(sigmoid1, &neuron.getFunction());
	ASSERT_NE(sigmoid2, &neuron.getFunction());
}

// @TODO: TBC