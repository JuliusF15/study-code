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

Character& Character::addItemToInventory(Item item){
    for(int i=0; i < MAX_INVENTORY; i++){
        if(inventory[i].getNameString() == ""){
            inventory[i] = item;
            return *this;
        }
    }
    std::cout << "Inventory Full, cant add " << item.getNameString() << std::endl;
    return *this;
};

Character& Character::removeLastItem(){
    for(int i=MAX_INVENTORY-1; i>=0; i--){
        if(inventory[i].getNameString() != ""){
            inventory[i] = Item();
            return *this;
        }
    }
    std::cout << "Inventory empty, cant remove an Item " << std::endl;
    return *this;
}

bool Character::isInventoryFull(){
    for(int i=0; i < MAX_INVENTORY; i++){
        if(inventory[i].getNameString() == ""){
            return false;
        }
    }
    return true;
}
