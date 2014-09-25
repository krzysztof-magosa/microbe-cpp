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

#ifndef __Microbe__Sigmoid__
#define __Microbe__Sigmoid__

#include "microbe/Function.hpp"

namespace microbe {
    class Sigmoid : public Function {
    public:
        double function(const double input);
        double derivative(const double functionOutput);
        double getUpperLimit();
        double getLowerLimit();
        bool hasFlatSpot();
        
    private:
        double getSlope();
    };
}

#endif /* defined(__Microbe__Sigmoid__) */
