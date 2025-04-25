#pragma once
#include <vector>
#include <memory>
#include "Player.h"
#include "Coach.h"
#include "TeamFactory.h"

class TeamFactory;

class Team {
protected:
    Coach coach;
    std::string name;
    std::vector<Player> players;
    int powerAttack;
    int powerDefend;

public:
    Team(Coach coach, std::string name, 
         std::vector<Player> players,
         int powerAttack, int powerDefend);

    static std::unique_ptr<Team> createTeam(TeamFactory& factory,
                                          const std::string& name,
                                          const Coach& coach,
                                          const std::vector<Player>& players);
    
    virtual void calculateStats();
    
    std::string getName() const;
    int getPowerAttack() const;
    int getPowerDefend() const;
    const Coach& getCoach() const;
};