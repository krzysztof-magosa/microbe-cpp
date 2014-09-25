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

#include "microbe/MultiLayerPerceptron.hpp"

namespace microbe {
    void MultiLayerPerceptron::run(void)
    {
        std::vector<Layer*>::iterator it;
        
        for (it = layers.begin(); it != layers.end(); ++it) {
            Layer &layer = **it;
            layer.run();
        }
    }
    
    std::vector<InputNeuron*> MultiLayerPerceptron::getInputNeurons(void)
    {
        std::vector<InputNeuron*> inputNeurons;
        std::vector<Neuron*>::iterator it;
        
        Layer &layer = *layers.front();
        std::vector<Neuron*> neurons = layer.getNeurons();
        
        for (it = neurons.begin(); it != neurons.end(); ++it) {
            Neuron &neuron = **it;
            
            if (neuron.getType() == Neuron::NeuronType::Input) {
                inputNeurons.push_back(dynamic_cast<InputNeuron*>(&neuron));
            }
        }
        
        return inputNeurons;
    }
    
    void MultiLayerPerceptron::setValues(std::vector<double> values)
    {
        std::vector<InputNeuron*> inputNeurons = getInputNeurons();
        
        for (int i = 0; i < values.size(); ++i) {
            InputNeuron &neuron = *inputNeurons.at(i);
            neuron.setInput(values.at(i));
        }
    }
    
    std::vector<double> MultiLayerPerceptron::getOutput(void)
    {
        Layer &layer = *layers.back();
        std::vector<double> result;
        
        std::vector<Neuron*> neurons = layer.getNeurons();
        std::vector<Neuron*>::iterator it;
        
        for (it = neurons.begin(); it != neurons.end(); ++it) {
            Neuron &neuron = **it;
            
            result.push_back(neuron.getOutput());
        }
        
        return result;
    }
    
    std::map<std::string, Neuron*> MultiLayerPerceptron::getNeuronsMap(void)
    {
        // @TODO
        return std::map<std::string, Neuron*>();
    }
    
    void MultiLayerPerceptron::interconnectLayers(Layer& first, Layer& second)
    {
        std::vector<Neuron*>::iterator it1;
        std::vector<Neuron*>::iterator it2;
        std::vector<Neuron*> neurons1 = first.getNeurons();
        std::vector<Neuron*> neurons2 = second.getNeurons();
        
        
        for (it1 = neurons1.begin(); it1 != neurons1.end(); ++it1) {
            Neuron &neuron1 = **it1;

            for (it2 = neurons2.begin(); it2 != neurons2.end(); ++it2) {
                Neuron &neuron2 = **it2;
                
                Connection::interconnect(neuron1, neuron2);
            }
        }
    }
    
    void MultiLayerPerceptron::addLayer(Layer& layer)
    {
        layers.push_back(&layer);
     
        if (layers.size() >= 2) {
            Layer &layer1 = *layers.at(layers.size() - 2);
            Layer &layer2 = *layers.at(layers.size() - 1);
            interconnectLayers(layer1, layer2);
        }
    }
    
    std::vector<Layer*> &MultiLayerPerceptron::getLayers(void)
    {
        return layers;
    }
}
