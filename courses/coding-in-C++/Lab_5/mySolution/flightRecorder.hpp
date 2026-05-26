#ifndef FLIGHTRECORDER_HPP
#define FLIGHTRECORDER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename A1, int A2>
void printFrame(const A1 (&array)[A2]){
    for(int i=0; i<A2; i++){
        std::cout << array[i] << std::endl;
    }
}

template <typename B1, int B2>
B1 smallestValue(const B1 (&array)[B2]){
    B1 smallestValue = array[0];
    for(int i=0; i<B2; i++){
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

void printVectorData(const std::vector<int> &data){
    for(auto i: data){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void sortVectorData(std::vector<int> &data){
    std::sort(data.begin(), data.end());
}


 
#endif