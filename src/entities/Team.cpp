#include "../../include/entities/Team.h"

Team::Team(Coach coach, std::string name, 
         std::vector<Player> players,
         int powerAttack, int powerDefend)
    : coach(coach), name(std::move(name)),
      players(std::move(players)),
      powerAttack(powerAttack), powerDefend(powerDefend) {}

void Team::calculateStats() {
    powerAttack = 0;
    powerDefend = 0;
    
    for(const auto& player : players) {
        powerAttack += player.getSpeed() + player.getAccuracy();
        powerDefend += player.getEndurance() + player.getDexterity();
    }
    
    const std::string strategy = coach.getStrategy();
    const int strategyPower = coach.getStrategyPower();
    
    if(strategy == "Attack") {
        powerAttack += strategyPower * 2;
    } else if(strategy == "Defense") {
        powerDefend += strategyPower * 2;
    } else { 
        powerAttack += strategyPower;
        powerDefend += strategyPower;
    }
}

std::string Team::getName() const { 
    return name; 
}

int Team::getPowerAttack() const { 
    return powerAttack; 
}

int Team::getPowerDefend() const { 
    return powerDefend; 
}

const Coach& Team::getCoach() const { 
    return coach; 
}

std::unique_ptr<Team> Team::createTeam(TeamFactory& factory,
                                     const std::string& name,
                                     const Coach& coach,
                                     const std::vector<Player>& players) {
    return factory.createTeam(name, coach, players);
}