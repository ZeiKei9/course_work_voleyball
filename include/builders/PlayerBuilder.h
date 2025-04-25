#pragma once

#include "../entities/Player.h"

class PlayerBuilder {
    Player player;
    
public:
    explicit PlayerBuilder(const std::string& name);
    
    PlayerBuilder& setEndurance(int value);
    PlayerBuilder& setDexterity(int value);
    PlayerBuilder& setSpeed(int value);
    PlayerBuilder& setAccuracy(int value);
    
    Player build() const;
};