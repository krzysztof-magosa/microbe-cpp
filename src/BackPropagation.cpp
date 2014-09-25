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

#include <algorithm>
#include <memory>
#include "microbe/BackPropagation.hpp"

namespace microbe {
    BackPropagation::BackPropagation(MultiLayerPerceptron& network)
    {
        this->network = &network;
        this->outputLayer = network.getLayers().back();
        
        for (size_t i = network.getLayers().size() - 1; i > 0; --i) {
            this->workingLayers.push_back(network.getLayers().at(i));
        }
        
        for (Layer *layer : workingLayers) {
            for (Neuron *neuron : layer->getNeurons()) {
                neuron->setLearningData(*(new BackPropagationLearningData()));
            }
        }
    }
    
    void BackPropagation::propagate(const std::vector<double> expectedOutput)
    {
        for (Layer* layer : workingLayers) {
            for (int index = 0; index < layer->getNeurons().size(); index++) {
                Neuron* neuron = layer->getNeurons().at(index);

                if (neuron->getType() == Neuron::NeuronType::Bias) {
                    continue;
                }

                BackPropagationLearningData *ld = dynamic_cast<BackPropagationLearningData*>(&neuron->getLearningData());
                double output = neuron->getOutput();

                if (layer == outputLayer) {
                    double derivative = neuron->getFunction().derivative(output);

                    if (neuron->getFunction().hasFlatSpot()) {
                        derivative += 0.1;
                    }

                    ld->gradient = (expectedOutput[index] - output) * derivative;
                }
                else {
                    double productSum = 0;

                    for (Connection* connection : neuron->getOutputConnections()) {
                        BackPropagationLearningData *nlLd = dynamic_cast<BackPropagationLearningData*>(&connection->getDestination().getLearningData());
                        productSum += (nlLd->gradient * connection->getWeight());
                    }

                    ld->gradient = neuron->getFunction().derivative(output) * productSum;
                }

                for (Connection* connection : neuron->getInputConnections()) {
                    double correction = learningRate * connection->getInput() * ld->gradient;
                    connection->incWeight(correction + (momentum * ld->correction));

                    ld->correction = correction;
                }
            }
        }
    }
    
    void BackPropagation::trainEpoch()
    {
        for (LearningSet *set : learningSets) {
            network->setValues(set->getInput());
            network->run();
            
            propagate(set->getOutput());
        }

        std::random_shuffle(learningSets.begin(), learningSets.end());
    }
}
