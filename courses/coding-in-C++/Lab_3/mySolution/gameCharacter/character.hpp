#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "Item.hpp"

class Character {
    private:
        int healthPoints;

    protected:
        static constexpr int MAX_INVENTORY = 10;
        std::string name;
        std::string type;
        int level;
        Item* inventory[MAX_INVENTORY] = {};
        bool hasWeapon;
        friend class Healer;
        
        public:
        Character(std::string name, std::string type, int level, int healthPoints): name(name), type(type), level(level), healthPoints(healthPoints), hasWeapon(false) {};
        std::string getName();
        int getLevel();
        Character& levelUp(int levels_up);
        Character& levelDown(int levels_down);
        Character& healthUp(int health_up);
        Character& healthDown(int health_down);
        Character& changeWeaponStatus(bool changeHasWeapon);

        Character& addItemToInventory(Item* item);
        Character& removeLastItem();
        Item* removeItemfromInventory(int index);
        Item* getItemfromInventory(int index);
        Item* getWeaponFromInventory() const;
        int getNumOfUsedSlots() const;
        int getHealthPoints() const;
        bool isInventoryFull();
        
        virtual void printStatus() const;
        
};

#endif