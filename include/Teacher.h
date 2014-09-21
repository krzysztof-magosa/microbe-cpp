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

#include <cmath>
#include "LearningSet.h"
#include "Network.h"

namespace microbe {
    class Teacher {
    public:
        void setGoal(const double value);
        void setLearningRate(const double value);
        void setMomentum(const double value);
        void addLearningSet(LearningSet& set);
        double calculateSquaredErrorEpoch(void);
        bool train(void);
        
    protected:
        virtual void trainEpoch(void) = 0;
        double squaredError(LearningSet& set);
        
        double goal = 0.01;
        double learningRate = 0.75;
        double momentum = 0.95;
        double lastEpochError;
        std::vector<LearningSet*> learningSets;
        Network* network;
    };
}

#endif /* defined(__Microbe__Teacher__) */
