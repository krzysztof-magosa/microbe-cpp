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

#ifndef __Microbe__MultiLayerPerceptron__
#define __Microbe__MultiLayerPerceptron__

#include "Network.h"
#include "Layer.h"
#include "InputNeuron.h"

namespace microbe {
    class MultiLayerPerceptron : public Network {
    public:
        void run(void);
        void setValues(std::vector<double> values);
        std::vector<double> getOutput(void);
        std::map<std::string, Neuron*> getNeuronsMap(void);
        std::vector<InputNeuron*> getInputNeurons(void);
        
        void addLayer(Layer&);
        std::vector<Layer*> &getLayers(void);
        
    protected:
        void interconnectLayers(Layer& first, Layer& second);
        std::vector<Layer*> layers;
    };
}

#endif /* defined(__Microbe__MultiLayerPerceptron__) */
