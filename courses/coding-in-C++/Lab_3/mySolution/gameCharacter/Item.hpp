#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>

class Item{
    protected:
        std::string name;
        std::string type;
    public:
        Item(std::string name): name(name), type("Generic"){};
        Item(std::string name, std::string type): name(name), type(type){};
        Item(){};
        
        std::string getName(){
            return name;
        }
        std::string getType(){
            return type;
        }
};

#endif