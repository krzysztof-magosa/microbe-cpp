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

#include <string>
#include <cstdio>

#include "microbe/Neuron.hpp"
#include "microbe/Sigmoid.hpp"
#include "microbe/InputLayer.hpp"
#include "microbe/Layer.hpp"
#include "microbe/MultiLayerPerceptron.hpp"
#include "microbe/LearningSet.hpp"
#include "microbe/BackPropagation.hpp"
#include "microbe/SmartLearningRate.hpp"

int main(int argc, char** args)
{
    // Function
    microbe::Sigmoid sigmoid;

    // Network definition (2, 2, 1)
    microbe::MultiLayerPerceptron network;
    microbe::InputLayer inputLayer(2);
    microbe::Layer hiddenLayer(2, sigmoid, true);
    microbe::Layer outputLayer(1, sigmoid, false);
    network.addLayer(inputLayer);
    network.addLayer(hiddenLayer);
    network.addLayer(outputLayer);

    // XOR truth table
    microbe::LearningSet set1({0, 0}, {0});
    microbe::LearningSet set2({0, 1}, {1});
    microbe::LearningSet set3({1, 0}, {1});
    microbe::LearningSet set4({1, 1}, {0});

    // Initialize teacher with XOR truth table
    microbe::BackPropagation bp(network);
    bp.addLearningSet(set1);
    bp.addLearningSet(set2);
    bp.addLearningSet(set3);
    bp.addLearningSet(set4);

    // Smart learning rate
    microbe::SmartLearningRate smartLearningRate;
    bp.registerPlugin(smartLearningRate);

    // Train
    bp.train();

    // Show the results
    for (microbe::LearningSet *set : bp.getLearningSets()) {
        network.setValues(set->getInput());
        network.run();

        char *tmp = new char[500];
        std::snprintf(
            tmp,
            500,
            "%1.0f xor %1.0f -> %1.2f (ideal: %1.0f)",
            set->getInput().at(0),
            set->getInput().at(1),
            network.getOutput().at(0),
            set->getOutput().at(0)
        );

        std::cout << tmp << std::endl;
    }

    return 0;
}
