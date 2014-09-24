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
#include "Connection.h"

TEST(NeuronTest, Type)
{
	microbe::Neuron neuron;
	ASSERT_EQ(microbe::Neuron::NeuronType::Plain, neuron.getType());
}

TEST(NeuronTest, Function)
{
	microbe::Sigmoid sigmoid1;
	microbe::Sigmoid sigmoid2;

	microbe::Neuron neuron;
	neuron.setFunction(sigmoid1);

	ASSERT_EQ(&sigmoid1, &neuron.getFunction());
	ASSERT_NE(&sigmoid2, &neuron.getFunction());
}

TEST(NeuronTest, Connections)
{
	microbe::Neuron neuron1;
	microbe::Neuron neuron2;
	microbe::Connection::interconnect(neuron1, neuron2);

	ASSERT_EQ(&neuron2, &neuron1.getOutputConnections().front()->getDestination());
	ASSERT_EQ(&neuron1, &neuron2.getInputConnections().front()->getSource());
}

// @TODO: TBC
