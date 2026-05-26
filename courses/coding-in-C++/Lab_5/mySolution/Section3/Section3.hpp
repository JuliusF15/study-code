#ifndef SECTION3_HPP
#define SECTION3_HPP

#include <iostream>
#include <vector>

template <typename T>
T vectorSum(const std::vector<T> &dataVector){
    T counter = 0;
    for(auto i: dataVector){
        counter += i;
    }
    return counter;
}

template <typename T>
T vectorMax(const std::vector<T> &dataVector){
    T maxValue = dataVector.front();
    for(auto i: dataVector){
        if(i>maxValue){
            maxValue = i;
        }
    }
    return maxValue;
}

template <typename T>
T vectorMin(const std::vector<T> &dataVector){
    T minValue = dataVector.front();
    for(auto i: dataVector){
        if(i<minValue){
            minValue = i;
        }
    }
    return minValue;
}

template <typename T>
void vectorMetrics(const std::vector<T> &dataVector){
    std::cout << "Vector: ";
    for(auto i: dataVector){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    std::cout << "Sum: " << vectorSum(dataVector) << " Max Value: " << vectorMax(dataVector) << " Min Value: " << vectorMin(dataVector) << std::endl;
}

template <>
void vectorMetrics<bool>(const std::vector<bool> &dataVector){
    int counter = 0;
    std::cout << "Vector: ";
    for(auto i: dataVector){
        std::cout << i << ", ";
        if(i == true){
            counter++;
        }
    }
    if(counter >= dataVector.size()-counter){
        std::cout << "True" << std::endl;
        return;
    }
    std::cout << "False" << std::endl;
    return;
}

template <typename T1, int T2>
std::vector<T1> transferToVector(const T1 (&array)[T2]){
    std::vector<T1> dataVector;
    for(int i=0; i<T2; i++){
        dataVector.push_back(array[i]);
    }
    return dataVector;
}

#endif