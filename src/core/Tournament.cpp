#include "../include/core/Tournament.h"


void Tournament::registerTeam(std::unique_ptr<Team> team) {
    if(!team)
        throw std::invalid_argument("Cannot register null team");
    teams.push_back(std::move(team));
}

void Tournament::runTournament() {
    if(teams.size() < 2)
        throw std::logic_error("Need at least 2 teams for tournament");
    
    while(teams.size() > 1) {
        std::vector<std::unique_ptr<Team>> nextRound;
        
        for(size_t i = 0; i < teams.size(); i += 2) {
            if(i+1 >= teams.size()) { // Нечетное количество команд
                nextRound.push_back(std::move(teams[i]));
                continue;
            }
            
            StandardMatchStrategy strategy;
            bool result = strategy.determineWinner(*teams[i], *teams[i+1]);
            
            if(result) {
                nextRound.push_back(std::move(teams[i]));
            } else {
                nextRound.push_back(std::move(teams[i+1]));
            }
        }
        
        teams = std::move(nextRound);
    }
    
    if(!teams.empty()) {
        std::cout << "Tournament winner: " << teams[0]->getName() << "\n";
    }
}

int Tournament::teamCount() const {
    return teams.size();
}