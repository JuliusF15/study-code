#include "character.hpp"

std::string Character::getName(){
    return name;
};

int Character::getLevel(){
    return level;
};

Character& Character::levelUp(int levels_up){
    level = level + levels_up;
    return *this;
};

Character& Character::levelDown(int levels_down){
    level = level - levels_down;
    return *this;
};

Character& Character::healthUp(int health_up){
    healthPoints = healthPoints + health_up;
    return *this;

};

Character& Character::healthDown(int health_down){
    healthPoints = healthPoints - health_down;
    return *this;

};

Character& Character::changeWeaponStatus(bool ChangeHasWeapon){
    this->hasWeapon = ChangeHasWeapon;
    return *this;
}

Character& Character::addItemToInventory(Item* item){
    for(int i=0; i < MAX_INVENTORY; i++){
        if(inventory[i] == nullptr){
            if(item->getType() == "Weapon" && hasWeapon == false){
                hasWeapon = true;
            }else if(item->getType() == "Weapon" && hasWeapon == true){
                std::cout << "Only one Weapon is allowed!" << std::endl;
                return *this;
            }
            inventory[i] = item;
            return *this;
        }
    }
    std::cout << "Inventory Full, cant add " << item->getName() << std::endl;
    return *this;
};

Character& Character::removeLastItem(){
    for(int i=MAX_INVENTORY-1; i>=0; i--){
        if(inventory[i] != nullptr){
            delete inventory[i];
            inventory[i] = nullptr;
            return *this;
        }
    }
    std::cout << "Inventory empty, cant remove an Item " << std::endl;
    return *this;
}

bool Character::isInventoryFull(){
    for(int i=0; i < MAX_INVENTORY; i++){
        if(inventory[i] == nullptr){
            return false;
        }
    }
    return true;
}
Item* Character::removeItemfromInventory(int index){
    if(index >= 0 && index < MAX_INVENTORY){
        if(inventory[index] != nullptr){
            Item* item = inventory[index];
            inventory[index] = nullptr;
            return item;
        }else{
            std::cout << "No Item in Slot: " << index << std::endl;
        }
    }
    return nullptr;
}

Item* Character::getItemfromInventory(int index){
    if(index >= 0 && index < MAX_INVENTORY){
        return inventory[index];
    }
    return nullptr;
}

Item* Character::getWeaponFromInventory() const{
    for(int i=0; i<MAX_INVENTORY; i++){
        if(inventory[i] != nullptr && inventory[i]->getType() == "Weapon"){
            return inventory[i];
        }
    }
    return nullptr;
}

int Character::getNumOfUsedSlots() const{
    int counter = 0;
    for(int i=0; i<MAX_INVENTORY; i++){
        if(inventory[i] != nullptr){
            counter++;
        }
    }
    return counter;
}

void Character::printStatus() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health Points: " << healthPoints << std::endl;
    std::cout << "No Character specific Points" << std::endl;
    std::cout << "Level: " << level << std::endl;
    
    if(this->getWeaponFromInventory() != nullptr){
        std::cout << "Weapon: " << this->getWeaponFromInventory()->getName() << std::endl;
    }else{
        std::cout << "No Weapon in Inventory" << std::endl;
    }

    std::cout << "Items in Inventory: " << this->getNumOfUsedSlots() << "/" << MAX_INVENTORY << std::endl;
}
