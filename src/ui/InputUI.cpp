#include "../../include/ui/InputUI.h"
#include "../../include/entities/Player.h"
#include "../../include/builders/PlayerBuilder.h"


std::string InputUI::read_string(const std::string& prompt) {
    std::string input;
    std::cout << "✨ " << prompt << ": ";
    std::getline(std::cin >> std::ws, input);
    return input;
}

int InputUI::read_int(const std::string& prompt, int min, int max) {
    int value;
    while(true) {
        std::cout << "✨ " << prompt << " [" << min << "-" << max << "]: ";
        if(std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "❗ Некорректный ввод. Попробуйте снова.\n";
    }
}

Player InputUI::create_player_interactive() {
    std::cout << "\n" << BORDER_TOP
              << "║ 🧑🦰 СОЗДАНИЕ НОВОГО ИГРОКА ║\n"
              << BORDER_BOTTOM;
    
    std::string name = read_string("Введите имя игрока");
    
    return Player::create(name)
        .setEndurance(read_int("Выносливость", 0, 10))
        .setDexterity(read_int("Ловкость", 0, 10))
        .setSpeed(read_int("Скорость", 0, 10))
        .setAccuracy(read_int("Точность", 0, 10))
        .build();
}

Coach InputUI::create_coach_interactive() {
    std::cout << "\n" << BORDER_TOP
              << "║ 👔 СОЗДАНИЕ ТРЕНЕРА                      ║\n"
              << BORDER_BOTTOM;
    
    std::string name = read_string("Введите имя тренера");
    std::string strategy = read_string("Стратегия (Атака/Защита/Баланс)");
    int power = read_int("Сила стратегии", 0, 10);
    
    return Coach(name, strategy, power);
}

std::vector<Player> InputUI::create_players_for_team() {
    std::vector<Player> players;
    std::cout << "\n" << BORDER_TOP
              << "║ 🏐 СОЗДАНИЕ КОМАНДЫ                      ║\n"
              << BORDER_BOTTOM;
    
    int count = read_int("Введите количество игроков в команде", 2, 12);
    for(int i = 0; i < count; i++) {
        std::cout << "\n👤 Игрок #" << i+1 << ":\n";
        players.push_back(create_player_interactive());
    }
    return players;
}