//
// Created by muham on 25.09.2025.
//

#ifndef ANKR_DECAY_ENEMIES_HPP
#define ANKR_DECAY_ENEMIES_HPP

#include "characters_enemies.hpp"

class DarkKnight : public Enemies {
public:
    DarkKnight() {
        name = "DarkKnight";
        health = 90;
        maxHealth = 150;
        attackPower = 15;
    };

    void useSpecialAbility(Characters &target) override;

private:
    void darkSlash(Characters &target) const;

    void bloodArmor();
};

class MotherWitch : public Enemies {
public:
    MotherWitch() {
        name = "Mother of Witches";
        health = 80;
        maxHealth = 80;
        attackPower = 10;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void evilMagic(Characters &target) const;

    void lifeThief(Characters &target);
};

class LavaDragon : public Enemies {
public:
    LavaDragon() {
        name = "Lava Dragon";
        health = 200;
        maxHealth = 200;
        attackPower = 25;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void fireBreath(Characters &target) const;

    void ashFlight(Characters &target) const;
};

class Kheon : public Enemies {
public:
    Kheon() {
        name = "Kheon";
        health = 90;
        maxHealth = 120;
        attackPower = 20;
    }

    void useSpecialAbility(Characters &target) override;

private:
    void burnEverything(Characters &target) const;

    void fairStrike(Characters &target) const;

    void darknessStorm(Characters &target);
};

#endif //ANKR_DECAY_ENEMIES_HPP