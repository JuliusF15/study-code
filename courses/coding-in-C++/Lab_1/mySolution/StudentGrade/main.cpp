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
    double finalGrade;
    std::string letterGrade;
    
    readStudentData(name, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, letterGrade, finalGrade);
    printReport(name, homework, midterm, finalExam, letterGrade, finalGrade);

    std::cout << finalGrade << " " << letterGrade << std::endl;

}