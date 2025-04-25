#include <iostream>
#include <memory>

#include "../include/builders/PlayerBuilder.h"
#include "../include/entities/Coach.h"
#include "../include/entities/TeamFactory.h"
#include "../include/core/Tournament.h"
#include "../include/ui/UI.h"
#include "../include/ui/InputUI.h"


void print_main_menu() {
    std::cout << "\n" << BORDER_TOP
              << "║ 🏐 ГЛАВНОЕ МЕНЮ ВОЛЕЙБОЛЬНОГО СИМУЛЯТОРА ║\n"
              << BORDER_BOTTOM
              << "1. Создать новую команду\n"
              << "2. Запустить турнир\n"
              << "3. Выход\n"
              << HEADER << "Выберите действие: ";
}

int main() {
    try {
        VolleyballTeamFactory factory;
        Tournament tournament;
        int choice;

        while(true) {
            print_main_menu();
            std::cin >> choice;
            std::cin.ignore();

            switch(choice) {
                case 1: {
                    std::string teamName = InputUI::read_string("Введите название команды");
                    Coach coach = InputUI::create_coach_interactive();
                    auto players = InputUI::create_players_for_team();
                    
                    auto team = factory.createTeam(teamName, coach, players);
                    TeamUI::display_stats(*team);
                    
                    tournament.registerTeam(std::move(team));
                    break;
                }
                case 2: {
                    if(tournament.teamCount() < 2) {
                        std::cout << ERROR_ICON 
                                  << " Для турнира нужно минимум 2 команды!\n";
                        break;
                    }
                    
                    std::cout << "\n🚀 Начало турнира!\n";
                    tournament.runTournament();
                    break;
                }
                case 3:
                    std::cout << "\n🎉 До новых встреч!\n";
                    return 0;
                default:
                    std::cout << ERROR_ICON << " Неверный выбор!\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "\n" << ERROR_ICON << " Ошибка: " << e.what() << std::endl;
        return 1;
    }
}