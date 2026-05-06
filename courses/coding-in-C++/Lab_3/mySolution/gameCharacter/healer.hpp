#ifndef HEALER_HPP
#define HEALER_HPP
#include <iostream>
#include <string>
#include "mage.hpp"

class Healer: public Mage{
    protected:

    public:
        Healer(std::string name, int level, int healthPoints, bool hasWeapon, int manaSkill):Mage(name, "Healer", level, healthPoints, hasWeapon, manaSkill) {};
        Healer& heal(Character& target);
};

#endif