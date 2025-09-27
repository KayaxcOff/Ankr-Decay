//
// Created by muham on 25.09.2025.
//

#ifndef ANKR_DECAY_CHARACTERS_HPP
#define ANKR_DECAY_CHARACTERS_HPP

#include <string>

class Characters {
private:
    int playY{}, playX{};
protected:
    std::string name;
    int health, maxHealth;
    int attackPower;
public:
    Characters(std::string name, const int hp, const int max_hp, const int attack)
        : name(std::move(name)), health(hp), maxHealth(max_hp), attackPower(attack) {}
    virtual ~Characters() = default;

    virtual void useSpecialAbility(Characters& target);

    void takeDamage(const int damage) {
        health -= damage;
    }

    void setPosition(const int y, const int x) {
        playY = y;
        playX = x;
    }

    [[nodiscard]] int getPosX() const {return playX;}
    [[nodiscard]] int getPosY() const {return playY;}
    [[nodiscard]] int getAttackPower() const {return attackPower;}
    [[nodiscard]] std::string getName() const {return name;}
    [[nodiscard]] int getHealth() const {return health;}
    [[nodiscard]] bool isAlive() const {return health > 0;}
};

#endif //ANKR_DECAY_CHARACTERS_HPP