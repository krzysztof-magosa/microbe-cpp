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

#ifndef __Microbe__Connection__
#define __Microbe__Connection__

#include <random>
#include "microbe/Neuron.hpp"
#include "microbe/LearningData.hpp"

namespace microbe {
    class Neuron;
    
    class Connection {
    public:
        Connection(Neuron& source, Neuron& destination);
        Neuron &getSource(void);
        Neuron &getDestination(void);
        void setLearningData(LearningData& data);
        LearningData &getLearningData(void);
        double getInput(void);
        double getWeightedInput(void);
        double getWeight(void);
        void setWeight(double weight);
        void incWeight(double value);
        void decWeight(double value);
        
        static Connection& interconnect(Neuron& source, Neuron& destination);
        
    protected:
        Neuron* source;
        Neuron* destination;
        double weight;
        LearningData* learningData;
        
    private:
        Connection();
    };
}

#endif /* defined(__Microbe__Connection__) */
