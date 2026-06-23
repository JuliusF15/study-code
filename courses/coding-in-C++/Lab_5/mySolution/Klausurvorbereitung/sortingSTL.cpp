#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void printVec(std::vector<T> &vector){
    for(auto i: vector){
        std::cout << i << " ";
    }
    std::cout << std::endl;s
}

bool isNine(int value){
    return value == 9;
}

int main(){
    std::vector<int> vector = {1 ,3 ,4, 5, 9, 9, 5, 9, 5, 4, 77};
    printVec(vector);
    std::sort(vector.begin(), vector.end());
    auto i = std::find(vector.begin(), vector.end(), 9);
    int amount = std::count_if(vector.begin(), vector.end(), isNine);
    std::cout << amount << std::endl;
    
    printVec(vector);
}
