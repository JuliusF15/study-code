#include <iostream>

/*
- bei vererbten Klassen werden alle Variablen und Methode übergeben, die Sichtbarkeit kann nicht weniger werden
deshalb kann man die neuen Klassen hier als Public übergeben, da die Protected Sachen Protected bleiben
- Da wir bei User einen Parametriesierten Konstruktor haben, müssen wir die Eingaben für diesen in den Konstruktor der neuen Klasse geben, und in diesem erst den User Konstruktor aufrufen
- protected Sachen können nur innerhalb der selben und der vererbten Klasse aufgerufen werden.
*/

class User{
    protected:
        std::string name;
        int id;
    public:
        User(std::string name, int id): name(name), id(id){};
        void printInfo(){ std::cout << name << " " << id << std::endl; }
};

class Student : public User{
    protected:
        std::string role;
    public:
        Student(std::string name, int id): User(name, id), role("Student"){};
        void printRole(){ std::cout << name << role << std::endl; }
};

class Teacher : public User{
    protected:
        std::string role;
    public:
        Teacher(std::string name, int id): User(name, id), role("Teacher"){};
        void printRole(){ std::cout << name << role << std::endl; }
};

int main(){
    Student student("Tom", 1234);
    Teacher teacher("Max", 9239);

    student.printInfo();
    student.printRole();
    
    teacher.printInfo();
    teacher.printRole();

    
}