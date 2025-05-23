
#include "../../include/core/Tournament.h"
#include "../../include/ui/UI.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <utility>

void Tournament::registerTeam(std::unique_ptr<Team> team) {
    teams.push_back(std::move(team));
}

int Tournament::teamCount() const {
    return static_cast<int>(teams.size());
}

void Tournament::runTournament() {
    if (teams.size() < 2) return;

    // Для отображения начальной сетки (копируем по значению)
    std::vector<Team> bracketView;
    for (const auto& team : teams) {
        bracketView.push_back(*team);
    }
    TournamentUI::show_bracket(bracketView);

    std::vector<std::unique_ptr<Team>> currentRound;
    for (auto& team : teams) {
        currentRound.push_back(std::move(team));
    }

    int round = 1;
    while (currentRound.size() > 1) {
        std::vector<std::unique_ptr<Team>> nextRound;

        std::cout << "\nРаунд " << round++ << ":\n";

        for (size_t i = 0; i < currentRound.size(); i += 2) {
            Team& t1 = *currentRound[i];
            Team& t2 = *currentRound[i + 1];

            MatchUI::show_scoreboard(t1, t2);
            MatchUI::show_match_progress(1, rand() % 26, rand() % 26);

            int result1 = t1.getPowerAttack() + t1.getPowerDefend();
            int result2 = t2.getPowerAttack() + t2.getPowerDefend();

            std::unique_ptr<Team> winner = (result1 >= result2)
                ? std::move(currentRound[i])
                : std::move(currentRound[i + 1]);

            std::cout << "Победитель: " << winner->getName() << "\n";
            nextRound.push_back(std::move(winner));
        }

        currentRound = std::move(nextRound);
    }

    if (!currentRound.empty()) {
        TournamentUI::show_winner(*currentRound.front());
    }
}
