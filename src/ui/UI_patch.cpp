
#include "../../include/ui/UI.h"
#include "../../include/ui/Styles.h"
#include <iostream>
#include <iomanip>

void MatchUI::show_scoreboard(const Team& team1, const Team& team2) {
    std::cout << BORDER_TOP
              << "║               ТЕКУЩИЙ СЧЁТ               ║\n"
              << "╠═════════════════════╦════════════════════╣\n"
              << "║ " << std::left << std::setw(14)
              << (TEAM_ICON + team1.getName()) << "        ║ "
              << std::setw(14) << (TEAM_ICON + team2.getName()) << "       ║\n"
              << "╠═════════════════════╬════════════════════╣\n"
              << "║ " << ATTACK_ICON << "Атака: " << std::setw(7)
              << team1.getPowerAttack() << "    ║ "
              << ATTACK_ICON << "Атака: " << std::setw(7)
              << team2.getPowerAttack() << "   ║\n"
              << "║ " << DEFENSE_ICON << "Защита: " << std::setw(6)
              << team1.getPowerDefend() << "    ║ "
              << DEFENSE_ICON << "Защита: " << std::setw(6)
              << team2.getPowerDefend() << "   ║\n"
              << BORDER_BOTTOM;
}

void MatchUI::show_match_progress(int set, int score1, int score2) {
    std::cout << BORDER_TOP
              << "║              ПРОГРЕСС МАТЧА              ║\n"
              << "╠══════════════════════════════════════════╣\n"
              << "║ Сет: " << std::setw(23) << set << "             ║\n"
              << "║ Счёт: " << std::setw(2) << score1 << " : "
              << std::setw(17) << score2 << "             ║\n"
              << BORDER_BOTTOM;
}

void TournamentUI::show_bracket(const std::vector<Team>& teams) {
    std::cout << BORDER_TOP
              << "║              ТУРНИРНАЯ СЕТКА             ║\n"
              << BORDER_BOTTOM;

    for (size_t i = 0; i + 1 < teams.size(); i += 2) {
        std::cout << "\n" << HEADER << "Матч " << (i / 2 + 1) << ":\n";
        std::cout << TEAM_ICON << std::left << std::setw(10)
                  << teams[i].getName() << " vs           "
                  << TEAM_ICON << teams[i + 1].getName() << "\n";
    }
}

void TournamentUI::show_winner(const Team& winner) {
    std::cout << WINNER_ICON << " ПОБЕДИТЕЛЬ: " << winner.getName() << " 🎉\n";
    TeamUI::display_stats(winner);
}

void TeamUI::display_stats(const Team& team) {
    std::cout << BORDER_TOP
              << "║            СТАТИСТИКА КОМАНДЫ            ║\n"
              << "╠══════════════════════════════════════════╣\n"
              << "║ " << TEAM_ICON << "Название: " 
              << std::left << std::setw(20) << team.getName() << "               ║\n"
              << "║ " << COACH_ICON << "Тренер: " 
              << std::setw(21) << team.getCoach().getName() << "               ║\n"
              << "╠══════════════════════════════════════════╣\n"
              << "║ " << ATTACK_ICON << "Сила атаки: " 
              << std::setw(16) << team.getPowerAttack() << "           ║\n"
              << "║ " << DEFENSE_ICON << "Сила защиты: " 
              << std::setw(15) << team.getPowerDefend() << "           ║\n"
              << BORDER_BOTTOM << "\n";
}

void TeamUI::show_player_stats(const Player& player) {
    std::cout << "\n" << HEADER << "Статистика игрока " << player.getName() << ":\n"
              << "🏋️  Выносливость: " << std::string(player.getEndurance(), '*') << "\n"
              << "🤸  Ловкость:     " << std::string(player.getDexterity(), '*') << "\n"
              << "🏃  Скорость:     " << std::string(player.getSpeed(), '*') << "\n"
              << "🎯 Точность:      " << std::string(player.getAccuracy(), '*') << "\n";
}
