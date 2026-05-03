#ifndef MAGE_HPP
#define MAGE_HPP
#include <iostream>
#include <string>
#include "character.hpp"

class Mage: public Character{
    protected:
        int manaSkill;
        std::string type;

    public:
        Mage(std::string name, int level, int healthPoints, bool hasWeapon):Character(name, level, healthPoints, hasWeapon), type("Mage") {};
        Mage& regenManaPoints(int points);
};

#endif