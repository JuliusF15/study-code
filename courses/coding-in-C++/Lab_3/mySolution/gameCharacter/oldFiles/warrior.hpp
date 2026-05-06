#ifndef WARRIOR_HPP
#define WARRIOR_HPP
#include <iostream>
#include <string>
#include "character.hpp"

class Warrior: public Character{
    protected:
        int weaponSkill;
        std::string type;

    public:
        Warrior(std::string name, int level, int healthPoints, bool hasWeapon, int weaponSkill):Character(name, "Warrior", level, healthPoints, hasWeapon), weaponSkill(weaponSkill) {};
        Warrior(std::string name, std::string type, int level, int healthPoints, bool hasWeapon, int weaponSkill):Character(name, type, level, healthPoints, hasWeapon), weaponSkill(weaponSkill) {};
        Warrior& regenWeaponPoints();

        void printStatus() const override;
};

#endif