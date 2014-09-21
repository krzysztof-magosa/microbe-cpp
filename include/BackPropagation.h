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

#ifndef __Microbe__BackPropagation__
#define __Microbe__BackPropagation__

#include "Teacher.h"
#include "MultiLayerPerceptron.h"
#include "LearningData.h"

namespace microbe {
    class BackPropagation : public Teacher {
    public:
        BackPropagation(MultiLayerPerceptron& network);

    protected:
        void trainEpoch(void);
        void propagate(const std::vector<double> expectedOutput);
        std::vector<Layer*> workingLayers;
        Layer *outputLayer;
        
        class BackPropagationLearningData : public LearningData {
        friend class BackPropagation;

        protected:
            double gradient;
            double correction;            
        };
    };
}

#endif /* defined(__Microbe__BackPropagation__) */
