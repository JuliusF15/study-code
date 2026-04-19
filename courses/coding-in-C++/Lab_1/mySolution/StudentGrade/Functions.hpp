#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

void readStudentData(std::string &name, std::uint_least8_t &homework, std::uint_least8_t &midterm, std::uint_least8_t &finalExam);

void calculateGrade(std::uint_least16_t &homework, std::uint_least16_t &midterm, std::uint_least16_t &finalExam, std::string &letterGrade, double &finalGrade);
