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
    healthPoints = healthPoints + health_down;
    return *this;

};

Character& Character::addItemToInventory(Item* item){
    for(int i=0; i < MAX_INVENTORY; i++){
        if(inventory[i] == nullptr){
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

Item* Character::getItemfromInventory(int index) const{
    return inventory[index];
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
    
    if(getWeaponFromInventory() != nullptr){
        std::cout << "Weapon: " << getWeaponFromInventory()->getName() << std::endl;
    }else{
        std::cout << "No Weapon in Inventory" << std::endl;
    }

    std::cout << "Items in Inventory: " << getNumOfUsedSlots() << "/" << MAX_INVENTORY << std::endl;
}
