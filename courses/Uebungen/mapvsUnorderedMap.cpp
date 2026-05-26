#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main(){
    std::map<int, std::string> map = {{1, "Hello"}, {2, "World,"}, {3, "this"}, {4, "is a"}, {5, "ordered"}, {6, "map"}};

    std::unordered_map<std::string, std::string> unorderedMap = {{"1", "Hello"}, {"2", "World,"}, {"3", "this"}, {"4", "is"}, {"5", "an unordered"}, {"6", "map"}};

    for(const auto& i : map){
        std::cout << i.first << ": " << i.second << std::endl;

    }
    std::cout << std::endl;

    for(const auto& i : unorderedMap){
        std::cout << i.first << ": " << i.second << std::endl;

    }
}