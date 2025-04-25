#include "../include/entities/Player.h"
#include "../include/builders/PlayerBuilder.h"

std::string Player::getName() const { 
    return name; 
}

int Player::getEndurance() const { 
    return endurance; 
}

int Player::getDexterity() const { 
    return dexterity; 
}

int Player::getSpeed() const { 
    return speed; 
}

int Player::getAccuracy() const { 
    return accuracy; 
}

int Player::getTotalStats() const { 
    return endurance + dexterity + speed + accuracy; 
}

PlayerBuilder Player::create(const std::string& name) {
    return PlayerBuilder(name);
}