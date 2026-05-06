#include "mage.hpp"

Mage& Mage::regenManaPoints(int points){
    manaSkill = manaSkill + points;
}

void Mage::printStatus() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health Points: " << healthPoints << std::endl;
    std::cout << "Mana Points:" << manaSkill << std::endl;
    std::cout << "Level: " << level << std::endl;
    
    if(getWeaponFromInventory() != nullptr){
        std::cout << "Weapon: " << getWeaponFromInventory()->getName() << std::endl;
    }else{
        std::cout << "No Weapon in Inventory" << std::endl;
    }

    std::cout << "Items in Inventory: " << getNumOfUsedSlots() << "/" << MAX_INVENTORY << std::endl;
}