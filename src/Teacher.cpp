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

#include "Teacher.h"

namespace microbe {
    void Teacher::setLearningRate(const double value)
    {
        learningRate = value;
    }

    void Teacher::setMomentum(const double value)
    {
        momentum = value;
    }
        
    void Teacher::addLearningSet(LearningSet& set)
    {
        learningSets.push_back(&set);
    }

    double Teacher::calculateSquaredErrorEpoch(void)
    {
        double error = 0;

        for (LearningSet* set : learningSets) {
            error += squaredError(*set);
        }

        lastEpochError = std::sqrt(error / learningSets.size());
        return lastEpochError;
    }

    bool Teacher::train(void)
    {
        // @TODO: To be implemented.
        trainEpoch();
        return true;
    }

    double Teacher::squaredError(LearningSet& set)
    {
        double error = 0.0;
        
        network->setValues(set.getInput());
        network->run();
        
        auto outputs = network->getOutput();
        auto expected = set.getOutput();

        for (int i = 0; i < outputs.size(); i++) {
            error += std::pow(outputs.at(i) - expected.at(i), 2);
        }

        return error;
    }
}
