#ifndef SUBCHARACTERS_HPP
#define SUBCHARACTERS_HPP
#include <iostream>
#include <string>
#include "character.hpp"

class Mage: public Character{
    protected:
        int manaSkill;

    public:
        Mage(std::string name, int level, int healthPoints, int manaSkill):Character(name, "Mage", level, healthPoints), manaSkill(manaSkill) {};
        Mage(std::string name, std::string type, int level, int healthPoints, int manaSkill):Character(name, type, level, healthPoints), manaSkill(manaSkill) {};
        Mage& regenManaPoints(int points);

        void printStatus() const override;
};

class Warrior: public Character{
    protected:
        int weaponSkill;

    public:
        Warrior(std::string name, int level, int healthPoints, int weaponSkill):Character(name, "Warrior", level, healthPoints), weaponSkill(weaponSkill) {};
        Warrior(std::string name, std::string type, int level, int healthPoints, int weaponSkill):Character(name, type, level, healthPoints), weaponSkill(weaponSkill) {};
        Warrior& regenWeaponPoints(int points);

        void printStatus() const override;
};

class Healer: public Mage{
    protected:

    public:
        Healer(std::string name, int level, int healthPoints, int manaSkill):Mage(name, "Healer", level, healthPoints, manaSkill) {};
        Healer& heal(Character& target);
};

class Thief: public Warrior{
    protected:

    public:
        Thief(std::string name, int level, int healthPoints, int weaponSkill):Warrior(name, "Thief", level, healthPoints, weaponSkill) {};
        Thief& steal(Character& target, int index);
    };

#endif