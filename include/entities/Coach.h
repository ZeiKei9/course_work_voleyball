#pragma once

#include <string>
#include <stdexcept>

class Coach {
    std::string name;
    std::string strategy;
    int strategyPower;
    
public:
    Coach(std::string name, std::string strategy, int power);
    
    std::string getName() const;
    std::string getStrategy() const;
    int getStrategyPower() const;
};