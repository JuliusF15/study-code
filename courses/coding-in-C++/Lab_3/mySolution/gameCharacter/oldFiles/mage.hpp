#ifndef MAGE_HPP
#define MAGE_HPP
#include <iostream>
#include <string>
#include "character.hpp"

class Mage: public Character{
    protected:
        int manaSkill;

    public:
        Mage(std::string name, int level, int healthPoints, bool hasWeapon, int manaSkill):Character(name, "Mage", level, healthPoints, hasWeapon), manaSkill(manaSkill) {};
        Mage(std::string name, std::string type, int level, int healthPoints, bool hasWeapon, int manaSkill):Character(name, type, level, healthPoints, hasWeapon), manaSkill(manaSkill) {};
        Mage& regenManaPoints(int points);

        void printStatus() const override;
};

#endif