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

#ifndef __Microbe__Function__
#define __Microbe__Function__

namespace microbe {
    class Function {
    public:
        virtual double function(const double input) = 0;
        // Due to performance reasons derivative() takes function() result
        virtual double derivative(const double functionOutput) = 0;
        virtual double getUpperLimit() = 0;
        virtual double getLowerLimit() = 0;
    };
}

#endif /* defined(__Microbe__Function__) */
