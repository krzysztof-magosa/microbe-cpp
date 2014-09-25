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

#include "microbe/Normalizer.hpp"

namespace microbe {
    Normalizer::Normalizer(const double minInput, const double maxInput, const double minOutput, const double maxOutput)
    {
        this->minInput = minInput;
        this->maxInput = maxInput;

        this->minOutput = minOutput;
        this->maxOutput = maxOutput;
    }

    double Normalizer::normalize(const double value)
    {
        return minOutput + (((value - minInput) / (maxInput - minInput)) * (maxOutput - minOutput));
    }

    std::vector<double> Normalizer::normalize(std::vector<double> values)
    {
        std::vector<double> result;

        for (double value : values) {
            result.push_back(normalize(value));
        }

        return result;
    }
}
