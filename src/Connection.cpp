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

#include "Connection.h"

namespace microbe {
    Connection::Connection(Neuron &source, Neuron &destination)
    {
        this->source = &source;
        this->destination = &destination;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        weight = -0.5 + dis(gen);
    }
    
    Neuron &Connection::getSource(void)
    {
        return *source;
    }
    
    Neuron &Connection::getDestination(void)
    {
        return *destination;
    }
    
    LearningData &Connection::getLearningData(void)
    {
        return *learningData;
    }
    
    void Connection::setLearningData(LearningData &data)
    {
        learningData = &data;
    }
    
    double Connection::getInput(void)
    {
        return source->getOutput();
    }
    
    double Connection::getWeightedInput(void)
    {
        return getInput() * weight;
    }
    
    double Connection::getWeight()
    {
        return weight;
    }
    
    void Connection::setWeight(double weight)
    {
        this->weight = weight;
    }
    
    void Connection::incWeight(double value)
    {
        this->weight += value;
    }
    
    void Connection::decWeight(double value)
    {
        this->weight -= value;
    }
    
    Connection &Connection::interconnect(Neuron &source, Neuron &destination)
    {
        Connection *connection = new Connection(source, destination);
        source.addOutputConnection(*connection);
        destination.addInputConnection(*connection);
        
        return *connection;
    }
}
