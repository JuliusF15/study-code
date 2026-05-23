#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename A1, typename A2>
void printFrame(const A1 (&array)[A2]){
    for(int i=0; i<size; i++){
        std::cout << array[i] << std::endl;
    }
}

template <typename S>
S smallestValue(const S *array, int size){
    S smallestValue = array[0];
    for(int i=0; i<size; i++){
        if(array[i] < smallestValue){
            smallestValue = array[i];
        }
    }
    return smallestValue;
}

template <typename T1, typename T2>
void telemetryTag(T1 value1, T2 value2, std::string label1, std::string label2){
    std::cout << label1 << ": " << value1 << " | " << label2 << value2 << std::endl;
}

int main(){
    int a = 1;
    int b = 2;
    std::string c = "C";
    std::string d = "D";
    const int size = 3;
    float frame[size]{12.2, 23.4, 23.5};

    swap(a, b);
    swap(c, d);
    printFrame(frame, size);
    auto smallValue = smallestValue(frame, size);


    std::cout << a << b << c << d << smallValue << std::endl;

}