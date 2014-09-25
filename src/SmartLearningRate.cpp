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

#include "microbe/SmartLearningRate.hpp"

namespace microbe {
    void SmartLearningRate::init()
    {
        this->teacher->setLearningRate(1.0 / this->teacher->getLearningSets().size());
    }
    
    void SmartLearningRate::preEpoch(void)
    {
        lastError = teacher->getLastEpochError();
    }

    void SmartLearningRate::adjustRate(const double ratio)
    {
        double rate = teacher->getLearningRate() * ratio;

        if (rate > 1.0) {
            rate = 1.0;
        }
        else if (rate <= 0.0) {
            rate = 0.000001;
        }

        teacher->setLearningRate(rate);
    }

    void SmartLearningRate::postEpoch(void)
    {
        if (ready) {
            if ((teacher->getLastEpochError() / lastError) > 1.04) {
                this->adjustRate(0.7);
            }
            else if ((teacher->getLastEpochError() - lastError) < 0.0) {
                this->adjustRate(1.02);
            }
        }
        else {
            ready = true;
        }
    }
}