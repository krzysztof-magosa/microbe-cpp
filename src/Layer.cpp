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

#include "Layer.hpp"

namespace microbe {
    Layer::Layer()
    {
    }
    
    Layer::Layer(const int neuronsCount, Function& function, const bool withBias)
    {
        for (int i = 1; i <= neuronsCount; ++i) {
            Neuron *neuron = new Neuron();
            neuron->setFunction(function);
            neurons.push_back(neuron);
        }
        
        if (withBias) {
            neurons.push_back(new BiasNeuron());
        }
    }
    
    std::vector<Neuron*> Layer::getNeurons(void)
    {
        return neurons;
    }
    
    void Layer::run(void)
    {
        std::vector<Neuron*>::iterator it;
        
        for (it = neurons.begin(); it != neurons.end(); ++it) {
            Neuron &neuron = **it;
            neuron.activate();
        }
    }

    bool Layer::hasBias()
    {
        std::vector<Neuron*>::iterator it;
        for (it = neurons.begin(); it != neurons.end(); ++it) {
            Neuron &neuron = **it;
            
            if (neuron.getType() == Neuron::NeuronType::Bias) {
                return true;
            }
        }
        
        return false;
    }
}
