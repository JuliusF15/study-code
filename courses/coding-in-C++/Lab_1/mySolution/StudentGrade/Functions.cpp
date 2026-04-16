#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include "Functions.hpp"

void readStudentData(std::string &name, std::uint_least8_t &homework, std::uint_least8_t &midterm, std::uint_least8_t &finalExam){
    std::cout << "Enter your Name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter the grade for your homework: ";
    while(!(std::cin >> homework) || homework < 0 || homework > 100){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' \n');
    }

    std::cout << "Enter the grade for your midterm: ";
    while(!(std::cin >> midterm) || midterm < 0 || midterm > 100){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' \n');
    }

    std::cout << "Enter the grade for your final Exam: ";
    while(!(std::cin >> finalExam) || finalExam < 0 || finalExam > 100){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' \n');
    }
}