//
// Created by muham on 26.09.2025.
//

#include <iostream>
#include <random>
#include "enemies.hpp"

int abilitySelection() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 3);
    return dis(gen);
}

void DarkKnight::useSpecialAbility(Characters &target) {
    int choice = abilitySelection();
    bool isValid = false;

    do {
        switch (choice) {
            case 1: darkSlash(target); isValid = true; break;
            case 2: bloodArmor(); isValid = true; break;
            default: choice = abilitySelection(); break;
        }
    } while (!isValid);
}

void DarkKnight::darkSlash(Characters &target) const {
    std::cout << name << " uses Dark Slash on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower);
}

void DarkKnight::bloodArmor() {
    std::cout << name << " uses Blood Armor to increase defense!" << std::endl;
    health = maxHealth;
}

void MotherWitch::useSpecialAbility(Characters &target) {
    int choice = abilitySelection();
    bool isValid = false;

    do {
        switch (choice) {
            case 1: evilMagic(target); isValid = true; break;
            case 2: lifeThief(target); isValid = true; break;
            default: choice = abilitySelection(); break;
        }
    } while (!isValid);
}

void MotherWitch::evilMagic(Characters &target) const {
    std::cout << name << " casts Evil Magic on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower);
}

void MotherWitch::lifeThief(Characters &target) {
    std::cout << name << " uses Life Thief on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower);
    health += attackPower;
    if (health > maxHealth) maxHealth = health;
}

void LavaDragon::useSpecialAbility(Characters &target) {
    int choice = abilitySelection();
    bool isValid = false;

    do {
        switch (choice) {
            case 1: fireBreath(target); isValid = true; break;
            case 2: ashFlight(target); isValid = true; break;
            default: choice = abilitySelection(); break;
        }
    } while (!isValid);
}

void LavaDragon::fireBreath(Characters &target) const {
    std::cout << name << " uses Fire Breath on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower);
}

void LavaDragon::ashFlight(Characters &target) const {
    std::cout << name << " uses Ash Flight to evade the next attack!" << std::endl;
    target.takeDamage(attackPower*2);
}

void Kheon::useSpecialAbility(Characters &target) {
    int choice = abilitySelection();
    bool isValid = false;

    do {
        switch (choice) {
            case 1: burnEverything(target); isValid = true; break;
            case 2: fairStrike(target); isValid = true; break;
            case 3: darknessStorm(target); isValid = true; break;
            default: choice = abilitySelection(); break;
        }
    } while (!isValid);
}

void Kheon::burnEverything(Characters &target) const {
    std::cout << name << " uses Burn Everything on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower);
}

void Kheon::fairStrike(Characters &target) const {
    std::cout << name << " uses Fair Strike on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower/2);
}

void Kheon::darknessStorm(Characters &target) {
    std::cout << name << " uses Darkness Storm on " << target.getName() << "!" << std::endl;
    target.takeDamage(attackPower*2);
    health = maxHealth;
}
