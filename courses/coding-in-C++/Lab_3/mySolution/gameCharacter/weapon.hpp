#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>
#include "Item.hpp"

class Weapon: public Item{
    protected:
        int damageValue;
    public:
        Weapon(std::string name, int damageValue):Item(name, "Weapon"), damageValue(damageValue) {};

};

#endif