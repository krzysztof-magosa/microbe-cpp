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

#include <iostream>
#include "microbe/TeacherStatus.hpp"

namespace microbe {
    void TeacherStatus::init()
    {
    }

    void TeacherStatus::preEpoch(void)
    {
        count++;
    }

    void TeacherStatus::postEpoch(void)
    {
        if (count % everyN == 0) {
            printStatus();
        }
    }

    void TeacherStatus::printStatus(void)
    {
        std::cout << "Iteration number: " << count << std::endl;
        std::cout << "Learning rate:    " << teacher->getLearningRate() << std::endl;
        std::cout << "Momentum:         " << teacher->getMomentum() << std::endl;
        std::cout << "Error:            " << teacher->getLastEpochError() << std::endl;
        std::cout << std::endl;
    }

    void TeacherStatus::setDisplayInterval(const int iterations)
    {
        everyN = iterations;
    }
}
