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

#include "microbe/InputLayer.hpp"
#include "microbe/InputNeuron.hpp"

namespace microbe {
    InputLayer::InputLayer(const int neuronsCount)
    {
        for (int i = 1; i <= neuronsCount; ++i) {
            neurons.push_back(new InputNeuron());
        }
    }
}
