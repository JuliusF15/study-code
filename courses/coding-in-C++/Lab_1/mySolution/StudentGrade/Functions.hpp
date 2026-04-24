#include <string> //nur das includen was man wirklich braucht
#include <cstdint>

void readStudentData(std::string &name, std::uint_least16_t &homework, std::uint_least16_t &midterm, std::uint_least16_t &finalExam);

void calculateGrade(std::uint_least16_t &homework, std::uint_least16_t &midterm, std::uint_least16_t &finalExam, std::string &letterGrade, double &finalGrade);

void printReport(std::string name, std::uint_least16_t homework, std::uint_least16_t midterm, std::uint_least16_t finalExam, std::string letterGrade, double finalGrade);

//Konstate Parameter mit const schreiben
//bei printReport mit Referenzen arbeiten