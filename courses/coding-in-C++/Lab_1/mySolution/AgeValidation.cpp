
#include <iostream>
#include <cstdint>
#include <limits>

namespace validation {
    bool isAdult(uint8_t age){
        uint8_t MIN_AGE = 18;
        if(age >= MIN_AGE){
            return true;
        }else{
            return false;
        }
    }
    bool isSenior(uint8_t age){
        uint8_t MAX_AGE = 65;
        if(age >= MAX_AGE){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    int age;
    std::cout << "Please enter your age: ";
    while(!(std::cin >> age) || age < 0 || age > 200){
        std::cout << "You did not enter a valid number between 0 and 200. Please try again.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
    }

    if(validation::isAdult(age) && !(validation::isSenior(age))){
        std::cout << "You are " << age << " years old." << std::endl;
        std::cout << "That means that you are an adult.";
    }else if(validation::isSenior(age)){
        std::cout << "You are " << age << " years old." << std::endl;
        std::cout << "That means that you are a Senior.";
    }else{
        std::cout << "You are " << age << " years old." << std::endl;
        std::cout << "That means that you are a kid.";
    }
    
}


