#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "Item.hpp"

class Character {
    protected:
        static constexpr int MAX_INVENTORY = 10;
        std::string name;
        int level;
        int healthPoints;
        Item inventory[MAX_INVENTORY];
        bool hasWeapon;
        friend class Healer;

    public:
        Character(std::string name, int level, int healthPoints, bool hasWeapon): name(name), level(level), healthPoints(healthPoints), hasWeapon(hasWeapon) {};
        std::string getName();
        int getLevel();
        Character& levelUp(int levels_up);
        Character& levelDown(int levels_down);
        Character& healthUp(int health_up);
        Character& healthDown(int health_down);
        Character& addItemToInventory(Item item);
        Character& removeLastItem();
        Item getItemfromInventory(int index);
        Item getWeaponFromInventory();
        bool isInventoryFull();
        Character& printStatus();
        
};

#endif