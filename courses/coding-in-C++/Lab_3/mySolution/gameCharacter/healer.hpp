#ifndef HEALER_HPP
#define HEALER_HPP
#include <iostream>
#include <string>
#include "mage.hpp"

class Healer: public Mage{
    protected:
        int manaSkill;
        std::string type;

    public:
        Healer(std::string name, int level, int healthPoints, bool hasWeapon):Mage(name, level, healthPoints, hasWeapon), type("healer") {};
        Healer& regenManaPoints();
};

#endif