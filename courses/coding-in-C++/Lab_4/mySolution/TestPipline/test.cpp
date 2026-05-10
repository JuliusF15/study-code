#include <iostream>

class Base{
    public: 
        static int counter;
        void printCounter(){
            std::cout << "Counter: " << counter << std::endl;
        }
};
int Base::counter = 0;

class Derived1: public Base{
    public:
        void increaseCounter(){
            counter++;
        }
};

class Derived2: public Base{
    public:
        void increaseCounter(){
            counter++;
        }
};

int main(){
    Derived1 class1;
    Derived2 class2;

    class1.printCounter();
    class2.printCounter();

    class1.increaseCounter();

    class1.printCounter();
    class2.printCounter();

    class2.increaseCounter();

    class1.printCounter();
    class2.printCounter();
}