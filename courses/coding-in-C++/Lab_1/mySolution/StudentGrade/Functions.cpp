#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include "Functions.hpp"

void readStudentData(std::string &name, std::uint_least16_t &homework, std::uint_least16_t &midterm, std::uint_least16_t &finalExam){
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100;
    
    if(!(std::cout << "Enter your Name: ")){
        std::cout << "Error reading Name!" << std::endl;
    }
    std::cin >> std::ws;
    std::getline(std::cin, name);

    std::cout << "Enter the grade for your homework: ";
    std::cin >> std::ws;
    while(!(std::cin >> homework) || homework < MIN_VALUE || homework > MAX_VALUE){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the grade for your midterm: ";
    std::cin >> std::ws;
    while(!(std::cin >> midterm) || midterm < MIN_VALUE || midterm > MAX_VALUE){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    std::cout << "Enter the grade for your final Exam: ";
    std::cin >> std::ws;
    while(!(std::cin >> finalExam) || finalExam < MIN_VALUE || finalExam > MAX_VALUE){
        std::cout << "Enter a valid number between 0 and 100:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}

void calculateGrade(std::uint_least16_t &homework, std::uint_least16_t &midterm, std::uint_least16_t &finalExam, std::string &letterGrade, double &finalGrade){
    const double WEIGHT_HOMEWORK = 0.4;
    const double WEIGHT_MIDTERM = 0.25;
    const double WEIGHT_FINALEXAM = 0.35;

    const int GRADE_A_VAL = 90;
    const int GRADE_B_VAL = 80;
    const int GRADE_C_VAL = 70;
    const int GRADE_D_VAL = 60;
    const int GRADE_E_VAL = 50;
    
    finalGrade = (WEIGHT_HOMEWORK*homework) + (WEIGHT_MIDTERM*midterm) + (WEIGHT_FINALEXAM*finalExam);

    if(finalGrade >= GRADE_A_VAL){
        letterGrade = 'A';
    }else if(finalGrade >= GRADE_B_VAL){
        letterGrade = 'B';
    }
    else if(finalGrade >= GRADE_C_VAL){
        letterGrade = 'C';
    }
    else if(finalGrade >= GRADE_D_VAL){
        letterGrade = 'D';
    }
    else if(finalGrade >= GRADE_E_VAL){
        letterGrade = 'E';
    }
    else if(finalGrade < GRADE_E_VAL){
        letterGrade = 'F';
    }

}