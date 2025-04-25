#pragma once

#include <memory>
#include "Team.h"

class Team;

class TeamFactory {
public:
    virtual ~TeamFactory() = default;
    virtual std::unique_ptr<Team> createTeam(
        const std::string& name,
        const Coach& coach,
        const std::vector<Player>& players
    ) = 0;
};

class VolleyballTeamFactory : public TeamFactory {
public:
    std::unique_ptr<Team> createTeam(
        const std::string& name,
        const Coach& coach,
        const std::vector<Player>& players
    ) override;
};