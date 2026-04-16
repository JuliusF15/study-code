
#include <iostream>
#include <cstdint>
#include <limits>

namespace validation {
    bool isAdult(uint8_t age){
        if(age >= 18){
            return true;
        }else{
            return false;
        }
    }
    bool isSenior(uint8_t age){
        if(age >= 65){
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
        std::cout << "You did not enter a valid number. Please try again." << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    }
         
    
}


