#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include "Functions.hpp"


int main(){
    std::string name;
    std::uint_least16_t homework;
    std::uint_least16_t midterm;
    std::uint_least16_t finalExam;
    readStudentData(name, homework, midterm, finalExam);

    std::cout << name << homework << midterm << finalExam << std::endl;
}