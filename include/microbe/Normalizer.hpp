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

#ifndef __Microbe__Normalizer__
#define __Microbe__Normalizer__

#include <vector>

namespace microbe {
    class Normalizer {
    public:
        Normalizer(const double minInput, const double maxInput, const double minOutput, const double maxOutput);

        double normalize(const double value);
        std::vector<double> normalize(std::vector<double> values);

    protected:
        double minInput;
        double maxInput;
        double minOutput;
        double maxOutput;
    };
}

#endif /* defined(__Microbe__Normalizer__) */
