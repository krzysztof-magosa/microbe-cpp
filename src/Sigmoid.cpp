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

#include "Sigmoid.hpp"
#include <math.h>

namespace microbe {
    double Sigmoid::function(const double input)
    {
        return 1.0 / (1.0 + exp(getSlope() * input));
    }
    
    double Sigmoid::derivative(const double functionOutput)
    {
        return functionOutput * (1.0 - functionOutput);
    }
    
    double Sigmoid::getUpperLimit()
    {
        return 1.0;
    }
    
    double Sigmoid::getLowerLimit()
    {
        return 0.0;
    }
    
    bool Sigmoid::hasFlatSpot()
    {
        return true;
    }

    double Sigmoid::getSlope()
    {
        return -1.0;
    }
}
