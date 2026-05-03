#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>

class Item{
    protected:
        std::string name;
    public:
        Item(std::string name): name(name){};
        Item(){};
        Item& getName(){
            std::cout << name << std::endl;
            return *this;
        }
        std::string getNameString(){
            return name;
        }
};

#endif