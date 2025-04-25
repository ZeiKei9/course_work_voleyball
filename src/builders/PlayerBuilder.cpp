#include "../../include/builders/PlayerBuilder.h"

PlayerBuilder::PlayerBuilder(const std::string& name) {
    player.name = name;
    player.endurance = 5;
    player.dexterity = 5;
    player.speed = 5;
    player.accuracy = 5;
}

PlayerBuilder& PlayerBuilder::setEndurance(int value) {
    if(value < 0 || value > 10) 
        throw std::invalid_argument("Invalid endurance value (0-10)");
    player.endurance = value;
    return *this;
}

PlayerBuilder& PlayerBuilder::setDexterity(int value) {
    if(value < 0 || value > 10)
        throw std::invalid_argument("Invalid dexterity value (0-10)");
    player.dexterity = value;
    return *this;
}

PlayerBuilder& PlayerBuilder::setSpeed(int value) {
    if(value < 0 || value > 10)
        throw std::invalid_argument("Invalid speed value (0-10)");
    player.speed = value;
    return *this;
}

PlayerBuilder& PlayerBuilder::setAccuracy(int value) {
    if(value < 0 || value > 10)
        throw std::invalid_argument("Invalid accuracy value (0-10)");
    player.accuracy = value;
    return *this;
}

Player PlayerBuilder::build() const {
    if(player.name.empty())
        throw std::logic_error("Player name cannot be empty");
    return player;
}