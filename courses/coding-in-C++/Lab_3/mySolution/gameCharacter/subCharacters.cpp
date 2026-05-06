#include "subCharacters.hpp"

Mage& Mage::regenManaPoints(int points){
    manaSkill = manaSkill + points;
}

void Mage::printStatus() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health Points: " << healthPoints << std::endl;
    std::cout << "Mana Points:" << manaSkill << std::endl;
    std::cout << "Level: " << level << std::endl;
    
    if(this->getWeaponFromInventory() != nullptr){
        std::cout << "Weapon: " << this->getWeaponFromInventory()->getName() << std::endl;
    }else{
        std::cout << "No Weapon in Inventory" << std::endl;
    }

    std::cout << "Items in Inventory: " << this->getNumOfUsedSlots() << "/" << MAX_INVENTORY << std::endl;
}

//-------------WARRIOR-------------//

Warrior& Warrior::regenWeaponPoints(int points){
    weaponSkill = weaponSkill + points;
}
void Warrior::printStatus() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health Points: " << healthPoints << std::endl;
    std::cout << "Mana Points:" << weaponSkill << std::endl;
    std::cout << "Level: " << level << std::endl;
    
    if(this->getWeaponFromInventory() != nullptr){
        std::cout << "Weapon: " << this->getWeaponFromInventory()->getName() << std::endl;
    }else{
        std::cout << "No Weapon in Inventory" << std::endl;
    }

    std::cout << "Items in Inventory: " << this->getNumOfUsedSlots() << "/" << MAX_INVENTORY << std::endl;
}

//-------------HEALER-------------//

Healer& Healer::heal(Character& target){
    target.healthPoints++;
    std::cout << "Healed " << target.getName() << std::endl;
}

//-------------Thief-------------//

Thief& Thief::steal(Character& target, int index){
    if(this->isInventoryFull()){
        std::cout << "Can't steal if Inventory is full!!" << std::endl;
    }else{
        if(weaponSkill > target.getLevel()){
            this->addItemToInventory(target.getItemfromInventory(index));
        }else{
            std::cout << "Target is to Strong" << std::endl;
        }
    }
}
