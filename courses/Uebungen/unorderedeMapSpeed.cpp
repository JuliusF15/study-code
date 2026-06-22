#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main(){
    std::unordered_map<int, float> map;
    
    std::cout << "Start" << std::endl;

    for(int i = 0; i<5000000; i++){
        map.insert({i, i+0.1});
    }
    std::cout << "Finished" << std::endl;
    return 0;
}