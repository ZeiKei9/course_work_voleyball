#pragma once

#include <functional>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../entities/Team.h"
#include "Styles.h"


template<typename T>
class Observable {
    std::vector<std::function<void(const T&)>> observers;
    
public:
    void subscribe(std::function<void(const T&)> observer);
    void notify(const T& data);
};

class MatchEvent {
public:
    enum Type { MATCH_START, POINT_SCORED, MATCH_END };
    Type type;
    const Team* team;
};

class MatchUI {
public:
    static void show_scoreboard(const Team& team1, const Team& team2);
    static void show_match_progress(int set, int score1, int score2);
};

class TournamentUI {
public:
    static void show_bracket(const std::vector<Team>& teams);
    static void show_winner(const Team& winner);
};

class TeamUI {
public:
    static void display_stats(const Team& team);
    static void show_player_stats(const Player& player);
};