#include "Section3.hpp"
#include <iostream>

int array[8] = {1,23,3,10,4,5,3,2};
 std::vector<bool> motorStatus = {true, false, false, true, false};
int main(){
    std::vector<int> v = transferToVector(array);
    vectorMetrics(v);
    vectorMetrics(motorStatus);

}