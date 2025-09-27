#include <iostream>
#include <memory>
#include <map>
#include <random>
#include <limits>
#include <chrono>
#include "game_board/light_kingdom.hpp"
#include "players/heros.hpp"
#include "villains/enemies.hpp"

class GameEngine {
private:
    static constexpr int PLAYER_Y = 2;
    static constexpr int PLAYER_X = 2;
    static constexpr int MAP_HEIGHT = 10;
    static constexpr int MAP_WIDTH = 20;
    static constexpr int ENEMY_COUNT = 5;

    std::unique_ptr<Heros> heros;
    std::map<std::pair<int, int>, std::unique_ptr<Enemies>> enemies;
    FallenKingdom fallen_kingdom_{MAP_HEIGHT, MAP_WIDTH};
    int playY, playX;

public:
    GameEngine() : playY(PLAYER_Y), playX(PLAYER_X) {}

    void displayInfo();

    void chooseHero() {
        int choice;
        bool isValid = false;

        do {
            std::cout << "Choose your Light character:" << std::endl;
            std::cout << "1- Aether\n2- Saynax\n3- Kahrayn\n4- Yroy" << std::endl;
            std::cout << "Enter the number of your choice: ";
            std::cin >> choice;

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
                continue;
            }

            switch (choice) {
                case 1: heros = std::make_unique<Aether>(); isValid = true; break;
                case 2: heros = std::make_unique<Saynax>(); isValid = true; break;
                case 3: heros = std::make_unique<Kahray>(); isValid = true; break;
                case 4: heros = std::make_unique<Yroy>(); isValid = true; break;
                default: heros = std::make_unique<Liora>(); isValid = true; break;
            }
        } while (!isValid);
        heros->displayInfo();
        heros->setPosition(playY, playX);
        fallen_kingdom_.setTile(playY, playX, TileType::PLAYER);
    }

    void spawnEnemies() {
        const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution distY(1, fallen_kingdom_.getHeight()-2);
        std::uniform_int_distribution distX(1, fallen_kingdom_.getWidth()-2);
        std::uniform_int_distribution typeDist(0, 2);

        for (int i=0; i<ENEMY_COUNT; ++i) {
            int y, x;
            int attempt = 0;

            do {
                y = distY(generator);
                x = distX(generator);
                attempt++;

                if (constexpr int maxAttempt = 100; attempt > maxAttempt) {
                    std::cerr << "Failed to place enemy after " << std::endl;
                    return;
                }
            } while (fallen_kingdom_.getTile(y, x) != TileType::EMPTY || y == heros->getPosY() && x == heros->getPosX());

            const int enemyType = typeDist(generator);
            std::unique_ptr<Enemies> enemy;

            switch (enemyType) {
                case 0: enemy = std::unique_ptr<DarkKnight>(); break;
                case 1: enemy = std::unique_ptr<MotherWitch>(); break;
                case 2: enemy = std::unique_ptr<Kheon>(); break;
                default: enemy = std::unique_ptr<LavaDragon>(); break;
            }
            enemy->setPosition(y, x);
            enemies[{y, x}] = std::move(enemy);
            fallen_kingdom_.setTile(y, x, TileType::ENEMY);
        }
    }

    void simulateBattle(int posY, int posX) {
        Enemies* enemy = enemies[{posY, posX}].get();

        std::cout << "== Battle Start ==" << std::endl;
        std::cout << heros->getName() << " vs " << enemy->getName() << std::endl;
        std::cout << "1-> Use your ability\n2-> Run away" << std::endl;

        while (heros->isAlive() && enemy->isAlive()) {
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            int action;
            bool battleOngoing = false;

            do {
                std::cout << "Choose your action: ";
                std::cin >> action;

                if (!(std::cin >> action)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    continue;
                }

                if (action == 1) {
                    std::cout << heros->getName() << "'s turn!" << std::endl;
                    heros->useSpecialAbility(*enemy);
                    battleOngoing = true;

                    if (enemy->isAlive()) {
                        std::cout << enemy->getName() << "'s turn!" << std::endl;
                        enemy->useSpecialAbility(*heros);
                    }
                } else if (action == 2) {
                    std::cout << "Use commands" << std::endl;
                    battleOngoing = true;
                } else {
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }
            } while (!battleOngoing);
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
        if (!heros->isAlive()) {
            std::cout << heros->getName() << "has been defeated" << std::endl;
            std::exit(0);
        }
        if (!enemy->isAlive()) {
            std::cout << heros->getName() << "has been defeated" << std::endl;
            std::cout << "== Battle End ==" << std::endl;
        }
    }

    void explorationLoop() {
        char input = ' ';

        while (input != 'q' && input != 'Q') {
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            std::cout << "Your position: (" << heros->getPosY() << ", " << heros->getPosX() << ")" << std::endl;
            std::cout << "Use W/A/S/D to move, Q to quit." << std::endl;
            std::cout << "Your move: ";
            std::cin >> input;

            fallen_kingdom_.display_board();
            fallen_kingdom_.setTile(heros->getPosY(), heros->getPosX(), TileType::EMPTY);

            int posY = heros->getPosY();
            int posX = heros->getPosX();

            switch (input) {
                case 'w': case 'W': posY--; break;
                case 's': case 'S': posY++; break;
                case 'a': case 'A': posX--; break;
                case 'd': case 'D': posX++; break;
                case 'q': case 'Q': std::cout << "Exiting the game." << std::endl; return;
                default: std::cout << "Invalid input. Please use W/A/S/D to move or Q to quit." << std::endl; continue;
            }

            if (const TileType tile = fallen_kingdom_.getTile(posY, posX); tile == TileType::WALL) {
                std::cout << "You hit a wall!" << std::endl;
                fallen_kingdom_.setTile(heros->getPosY(), heros->getPosX(), TileType::PLAYER);
            } else if (tile == TileType::ENEMY) {
                std::cout << "You encountered an enemy!" << std::endl;
                simulateBattle(posY, posX);
                fallen_kingdom_.setTile(posY, posX, TileType::EMPTY);
                heros->setPosition(posY, posX);
            } else {
                heros->setPosition(posY, posX);
                fallen_kingdom_.setTile(heros->getPosY(), heros->getPosX(), TileType::PLAYER);
            }
        }
    }

    void ankr_loop() {
        chooseHero();
        spawnEnemies();
        explorationLoop();
    }
};

int main() {
    std::cout << "Want to start the game? (y/n): ";
    char start;
    std::cin >> start;
    if (start == 'y' || start == 'Y') {
        GameEngine game;
        game.displayInfo();
        game.ankr_loop();
    } else {
        std::cout << "Exiting the game." << std::endl;
    }
    return 0;
}