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

#ifndef __Microbe__Neuron__
#define __Microbe__Neuron__

#include <vector>
#include "Function.hpp"
#include "Connection.hpp"
#include "LearningData.hpp"

namespace microbe {
    class Connection;
    
    class Neuron {
    public:
        enum class NeuronType {
            Plain,
            Bias,
            Input
        };
        
        void setFunction(Function& function);
        Function &getFunction(void);
        double getOutput(void);
        double getSum(void);
        std::vector<Connection*> getInputConnections(void);
        std::vector<Connection*> getOutputConnections(void);
        virtual void addInputConnection(Connection& connection);
        void addOutputConnection(Connection& connection);
        void setLearningData(LearningData& data);
        LearningData& getLearningData(void);

        virtual double activate(void);
        virtual NeuronType getType(void);
        
    protected:
        double output;
        double sum;
        Function *function;
        std::vector<Connection*> inputConnections;
        std::vector<Connection*> outputConnections;
        LearningData *learningData;
    };
}

#endif /* defined(__Microbe__Neuron__) */
