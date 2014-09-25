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

#ifndef __Microbe__Network__
#define __Microbe__Network__

#include <vector>
#include <map>
#include "Neuron.hpp"
#include "InputNeuron.hpp"

namespace microbe {
    class Network {
    public:
        virtual void run(void) = 0;
        virtual void setValues(std::vector<double> values) = 0;
        virtual std::vector<double> getOutput(void) = 0;
        virtual std::map<std::string, Neuron*> getNeuronsMap(void) = 0;
        virtual std::vector<InputNeuron*> getInputNeurons(void) = 0;
    };
}

#endif /* defined(__Microbe__Network__) */
