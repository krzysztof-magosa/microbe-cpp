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

#include "gtest/gtest.h"
#include "microbe/Normalizer.hpp"

TEST(NormalizerTest, Normalize)
{
    microbe::Normalizer normalizer(0.0, 255.0, 0.0, 1.0);

    EXPECT_NEAR(0.0, normalizer.normalize(0.0), 0.00001);
    EXPECT_NEAR(0.5, normalizer.normalize(127.5), 0.00001);
    EXPECT_NEAR(1.0, normalizer.normalize(255.0), 0.00001);
}

TEST(NormalizerTest, NormalizeVector)
{
    microbe::Normalizer normalizer(0.0, 255.0, 0.0, 1.0);

    std::vector<double> values { 0.0, 127.5, 255.0 };
    std::vector<double> expected { 0.0, 0.5, 1.0 };

    auto processed = normalizer.normalize(values);

    for (int i = 0; i < values.size(); i++) {
        EXPECT_NEAR(expected.at(i), processed.at(i), 0.00001);
    }
}
