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

#include "Tanh.hpp"
#include <math.h>

namespace microbe {
    double Tanh::function(const double input)
    {
        return tanh(input);
    }
    
    double Tanh::derivative(const double functionOutput)
    {
        return 1.0 - (functionOutput * functionOutput);
    }
    
    double Tanh::getUpperLimit()
    {
        return 1.0;
    }
    
    double Tanh::getLowerLimit()
    {
        return -1.0;
    }

    bool Tanh::hasFlatSpot()
    {
        return false;
    }
}
