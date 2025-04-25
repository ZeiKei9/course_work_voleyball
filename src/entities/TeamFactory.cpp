#include "../../include/entities/TeamFactory.h"

std::unique_ptr<Team> VolleyballTeamFactory::createTeam(
    const std::string& name,
    const Coach& coach,
    const std::vector<Player>& players
) {
    auto team = std::make_unique<Team>(coach, name, players, 0, 0);
    team->calculateStats();
    return team;
}
