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

#ifndef __Microbe__Layer__
#define __Microbe__Layer__

#include <iostream>
#include <vector>
#include "microbe/Neuron.hpp"
#include "microbe/BiasNeuron.hpp"

namespace microbe {
    class Layer {
    public:
        Layer(const int neuronsCount, Function& function, const bool withBias);
        Layer(const int neuronsCount, Function& function) : Layer(neuronsCount, function, true) {};
        Layer(void);
        std::vector<Neuron*> getNeurons();
        void run(void);
        bool hasBias(void);
        
    protected:
        std::vector<Neuron*> neurons;
    };
}

#endif /* defined(__Microbe__Layer__) */
