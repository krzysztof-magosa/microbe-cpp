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
#include "InputNeuron.h"

TEST(NeuronTest, Type)
{
	microbe::InputNeuron neuron;
	ASSERT_EQ(microbe::Neuron::NeuronType::Input, neuron.getType());
}

TEST(NeuronTest, Output)
{
	microbe::InputNeuron neuron;

	neuron.setInput(0.12421);
	EXPECT_NEAR(0.12421, neuron.activate(), 0.00001);

	neuron.setInput(0.62421);
	EXPECT_NEAR(0.62421, neuron.activate(), 0.00001);
}
