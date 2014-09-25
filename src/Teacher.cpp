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

#include "Teacher.hpp"
#include "TeacherPlugin.hpp"

namespace microbe {
    void Teacher::setGoal(const double value)
    {
        if (value <= 0.0) {
            throw std::invalid_argument("Goal must be positive number.");
        }

        goal = value;
    }

    void Teacher::setLearningRate(const double value)
    {
        if (value <= 0.0) {
            throw std::invalid_argument("Learning rate cannot be 0.0 or negative number.");
        }

        if (value > 1.0) {
            throw std::invalid_argument("Learning rate cannot be higher than 1.0.");
        }

        learningRate = value;
    }

    double Teacher::getLearningRate(void)
    {
        return learningRate;
    }

    void Teacher::setMomentum(const double value)
    {
        if (value < 0.0) {
            throw std::invalid_argument("Momentum cannot be negative.");
        }

        if (value > 1.0) {
            throw std::invalid_argument("Momentum cannot be higher than 1.0.");
        }

        momentum = value;
    }
        
    void Teacher::addLearningSet(LearningSet& set)
    {
        learningSets.push_back(&set);
    }

    std::vector<LearningSet*> Teacher::getLearningSets(void)
    {
        return learningSets;
    }

    double Teacher::getLastEpochError(void)
    {
        return lastEpochError;
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
        calculateSquaredErrorEpoch();

        while (lastEpochError > goal) {
            firePreEpoch();
            trainEpoch();
            calculateSquaredErrorEpoch();
            firePostEpoch();
        }

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

    void Teacher::registerPlugin(TeacherPlugin& plugin)
    {
        plugin.setTeacher(this);
        plugin.init();
        plugins.push_back(&plugin);
    }

    void Teacher::firePreEpoch(void)
    {
        for (TeacherPlugin *plugin : plugins) {
            plugin->preEpoch();
        }
    }

    void Teacher::firePostEpoch(void)
    {
        for (TeacherPlugin *plugin : plugins) {
            plugin->postEpoch();
        }
    }    
}
