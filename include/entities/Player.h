#pragma once

#include <string>
#include <stdexcept>

class PlayerBuilder;

class Player {
    std::string name;
    int endurance;
    int dexterity;
    int speed;
    int accuracy;
    
    friend class PlayerBuilder;
    
public:
    std::string getName() const;
    int getEndurance() const;
    int getDexterity() const;
    int getSpeed() const;
    int getAccuracy() const;
    int getTotalStats() const;

    static PlayerBuilder create(const std::string& name);
};