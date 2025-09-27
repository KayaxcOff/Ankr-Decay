//
// Created by muham on 25.09.2025.
//

#include "heros.hpp"
#include "../villains/characters_enemies.hpp"

void Aether::useSpecialAbility(Characters &target) {
    int choice;
    bool isValid = false;

    do {
        std::cout << "1-> Cosmic Strike" << std::endl;
        std::cout << "2-> Celestial Protection" << std::endl;
        std::cout << "3-> Heavenly Heal" << std::endl;
        std::cout << "Choose a special ability (1-3): ";
        std::cin >> choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: cosmicStrike(target); isValid = true; break;
            case 2: celestialProtection(target); isValid = true; break;
            case 3: heavenlyHeal(); isValid = true; break;
            default: break;
        }
    } while (!isValid);
}

void Aether::cosmicStrike(Characters &target) const {
    std::cout << "Aether uses Cosmic Strike on " << target.getName() << std::endl;
    target.takeDamage(attackPower);
}

void Aether::celestialProtection(Characters &target) {
    std::cout << "Aether uses Celestial Protection on " << target.getName() << std::endl;
    target.takeDamage(attackPower/2);
    health += attackPower/2;
    if (health > maxHealth) maxHealth = health;
}

void Aether::heavenlyHeal() {
    health = maxHealth;
}

void Saynax::useSpecialAbility(Characters &target) {
    int choice;
    bool isValid = false;

    do {
        std::cout << "1-> Eyes of Death" << std::endl;
        std::cout << "2-> Slow Death" << std::endl;
        std::cout << "3-> Lief Thief" << std::endl;
        std::cout << "Choose a special ability (1-3): ";
        std::cin >> choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: eyesOfDeath(target); isValid = true; break;
            case 2: slowDeath(target); isValid = true; break;
            case 3: liefThief(target); isValid = true; break;
            default: break;
        }
    } while (!isValid);
}

void Saynax::eyesOfDeath(Characters &target) const {
    std::cout << "Saynax uses Eyes of Death on " << target.getName() << std::endl;
    target.takeDamage(attackPower * 2);
}

void Saynax::slowDeath(Characters &target) const {
    const int damage = attackPower / 10;
    std::cout << "Saynax uses Slow Death on " << target.getName() << std::endl;
    for (int i = 0; i < 10; ++i) target.takeDamage(damage);
}

void Saynax::liefThief(Characters &target) {
    const int healPoint = attackPower / 2;
    health += healPoint;
    if (health > maxHealth) maxHealth = health;
    std::cout << "Saynax uses Lief Thief on " << target.getName() << std::endl;
    target.takeDamage(healPoint);
}

void Kahray::useSpecialAbility(Characters &target) {
    int choice;
    bool isValid = false;

    do {
        std::cout << "1-> Demolition Hammer" << std::endl;
        std::cout << "2-> Rune Shield" << std::endl;
        std::cout << "Choose a special ability (1-2): ";
        std::cin >> choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 2." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: demolitionHammer(target); isValid = true; break;
            case 2: runeShield(); isValid = true; break;
            default: break;
        }
    } while (!isValid);
}

void Kahray::demolitionHammer(Characters &target) const {
    std::cout << "Kahray uses Demolition Hammer on " << target.getName() << std::endl;
    target.takeDamage(attackPower);
}

void Kahray::runeShield() {
    std::cout << "Kahray uses Rune Shield and increases max health!" << std::endl;
    maxHealth += 20;
    health = maxHealth/2;
}

void Yroy::useSpecialAbility(Characters &target) {
    int choice;
    bool isValid = false;

    do {
        std::cout << "1-> Earthquake" << std::endl;
        std::cout << "2-> Rock Rain" << std::endl;
        std::cout << "3-> Stone Skin" << std::endl;
        std::cout << "Choose a special ability (1-3): ";
        std::cin >> choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: earthquake(target); isValid = true; break;
            case 2: rockRain(target); isValid = true; break;
            case 3: stoneSkin(); isValid = true; break;
            default: break;
        }
    } while (!isValid);
}

void Yroy::earthquake(Characters &target) const {
    std::cout << "Yroy uses Earthquake on " << target.getName() << std::endl;
    target.takeDamage(attackPower);
}

void Yroy::rockRain(Characters &target) const {
    std::cout << "Yroy uses Rock Rain on " << target.getName() << std::endl;
    const int damage = attackPower / 5;
    for (int i = 0; i < 5; ++i) target.takeDamage(damage);
}

void Yroy::stoneSkin() {
    std::cout << "Yroy uses Stone Skin" << std::endl;
    health += 15;
    if (health > maxHealth) maxHealth = health;
}

void Liora::useSpecialAbility(Characters &target) {
    int choice;
    bool isValid = false;

    do {
        std::cout << "1-> Lief Thief" << std::endl;
        std::cout << "2-> Light Star" << std::endl;
        std::cout << "3-> Creation of Runes" << std::endl;
        std::cout << "Choose a special ability (1-3): ";
        std::cin >> choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: lifeSong(target); isValid = true; break;
            case 2: lightStar(target); isValid = true; break;
            case 3: creationOfRunes(); isValid = true; break;
            default: break;
        }
    } while (!isValid);
}

void Liora::lifeSong(Characters &target) const {
    std::cout << "Liora uses Life Song on " << target.getName() << std::endl;
    target.takeDamage(attackPower);
}

void Liora::lightStar(Characters &target) const {
    std::cout << "Liora uses Light Star on " << target.getName() << std::endl;
    target.takeDamage(attackPower * 2);
}

void Liora::creationOfRunes() {
    std::cout << "Liora uses Creation of Runes" << std::endl;
    health += 20;
    if (health > maxHealth) maxHealth = health;
}