#pragma once

#include <iostream>
#include <limits>
#include <vector>

#include "../entities/Player.h"
#include "../entities/Coach.h"
#include "Styles.h"

class InputUI {
public:
    static std::string read_string(const std::string& prompt);
    static int read_int(const std::string& prompt, int min, int max);
    static Player create_player_interactive();
    static Coach create_coach_interactive();
    static std::vector<Player> create_players_for_team();
};