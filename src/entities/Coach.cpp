#include "../include/entities/Coach.h"


Coach::Coach(std::string name, std::string strategy, int power)
    : name(std::move(name)), 
      strategy(std::move(strategy)), 
      strategyPower(power) {
    if(strategyPower < 0 || strategyPower > 10)
        throw std::invalid_argument("Strategy power must be 0-10");
}

std::string Coach::getName() const { 
    return name; 
}

std::string Coach::getStrategy() const { 
    return strategy; 
}

int Coach::getStrategyPower() const { 
    return strategyPower; 
}