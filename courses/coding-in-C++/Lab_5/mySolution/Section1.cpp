#include "flightRecorder.hpp"

int main(){
    int a = 1;
    int b = 2;
    std::string c = "C";
    std::string d = "D";
    const int size = 10;
    float frame[size]{12, 21, 42, 24, 23, 54, 6,23 ,34,3};

    swap(a, b);
    swap(c, d);
    printFrame(frame);
    auto smallValue = smallestValue(frame);


    std::cout << a << b << c << d << " " << smallValue << std::endl;

}