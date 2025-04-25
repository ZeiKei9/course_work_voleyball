#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "../entities/Team.h"
#include "Match.h"

class Tournament {
    std::vector<std::unique_ptr<Team>> teams;
    
public:
    void registerTeam(std::unique_ptr<Team> team);
    void runTournament();
    int teamCount() const;
};