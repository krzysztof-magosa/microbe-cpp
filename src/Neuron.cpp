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

#include "Neuron.h"

namespace microbe {
    void Neuron::setFunction(Function& function)
    {
        this->function = &function;
    }
    
    Function &Neuron::getFunction(void)
    {
        return *function;
    }
    
    double Neuron::getOutput(void)
    {
        return output;
    }
    
    double Neuron::getSum(void)
    {
        return sum;
    }
    
    std::vector<Connection*> Neuron::getInputConnections(void)
    {
        return inputConnections;
    }
    
    std::vector<Connection*> Neuron::getOutputConnections(void)
    {
        return outputConnections;
    }
    
    void Neuron::addInputConnection(Connection &connection)
    {
        inputConnections.push_back(&connection);
    }
    
    void Neuron::addOutputConnection(Connection &connection)
    {
        outputConnections.push_back(&connection);
    }
    
    void Neuron::setLearningData(LearningData &data)
    {
        learningData = &data;
    }
    
    LearningData &Neuron::getLearningData(void)
    {
        return *learningData;
    }
    
    double Neuron::activate()
    {
        sum = 0;
        
        std::vector<Connection*>::iterator it;
        for (it = inputConnections.begin(); it != inputConnections.end(); ++it) {
            Connection &conn = **it;
            sum += conn.getWeightedInput();
        }

        output = function->function(sum);
        
        return output;
    }
    
    Neuron::NeuronType Neuron::getType(void)
    {
        return NeuronType::Plain;
    }
}
