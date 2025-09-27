//
// Created by muham on 25.09.2025.
//

#ifndef ANKR_DECAY_HEROS_HPP
#define ANKR_DECAY_HEROS_HPP

#include <iostream>
#include "characters_heros.hpp"

class Aether final : public Heros {
public:
    Aether() {
        name = "Aether";
        health = 70;
        maxHealth = 120;
        attackPower = 25;
    }

    void displayInfo() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << "/" << maxHealth << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void cosmicStrike(Characters &target) const;

    void celestialProtection(Characters &target);

    void heavenlyHeal();
};

class Saynax final : public Heros {
public:
    Saynax() {
        name = "Saynax";
        health = 100;
        maxHealth = 110;
        attackPower = 20;
    }

    void displayInfo() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << "/" << maxHealth << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void eyesOfDeath(Characters &target) const;

    void slowDeath(Characters &target) const;

    void liefThief(Characters &target);
};

class Kahray final : public Heros {
public:
    Kahray() {
        name = "Kahray";
        health = 35;
        maxHealth = 70;
        attackPower = 10;
    }

    void displayInfo() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << "/" << maxHealth << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void demolitionHammer(Characters &target) const;

    void runeShield();
};

class Yroy final : public Heros {
    Yroy() {
        name = "Yroy";
        health = 70;
        maxHealth = 90;
        attackPower = 20;
    }

    void displayInfo() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << "/" << maxHealth << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void earthquake(Characters &target) const;

    void rockRain(Characters &target) const;

    void stoneSkin();
};

class Liora final : public Heros {
public:
    Liora() {
        name = "Liora";
        health = 80;
        maxHealth = 90;
        attackPower = 15;
    }

    void displayInfo() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << "/" << maxHealth << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void lifeSong(Characters &target) const;

    void lightStar(Characters &target) const;

    void creationOfRunes();
};

#endif //ANKR_DECAY_HEROS_HPP