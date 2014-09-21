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

#ifndef __Microbe__Teacher__
#define __Microbe__Teacher__

#include <iostream>
#include "LearningSet.h"

namespace microbe {
    template <class T>
    class Teacher {
    public:
        void setLearningRate(const double value);
        void setMomentum(const double value);
        void addLearningSet(const LearningSet &set);
        double calculateSquaredErrorEpoch(void);
        bool train(void);

    protected:
        virtual void trainEpoch(void) = 0;
        double squaredError(const LearningSet &set);
        
        double learningRate = 0.75;
        double momentum = 0.95;
        double lastEpochError;
        std::vector<LearningSet*> learningData;
        T *network;
    };
}

#endif /* defined(__Microbe__Teacher__) */
