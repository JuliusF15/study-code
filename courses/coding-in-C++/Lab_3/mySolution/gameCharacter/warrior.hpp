#ifndef WARRIOR_HPP
#define WARRIOR_HPP
#include <iostream>
#include <string>
#include "character.hpp"

class Warrior: public Character{
    protected:
        int manaSkill;
        std::string type;

    public:
        Warrior(std::string name, int level, int healthPoints, bool hasWeapon):Character(name, level, healthPoints, hasWeapon), type("Warrior") {};
        Warrior& regenWeaponPoints();
};

#endif