#include "Functions.hpp"

int main(){
    std::vector<int> intVector = {1, 2, 4, 5, 6, 7, 10};
    std::vector<float> floatVector = {1.3, 2, 0.6, 5, 6, 7.99, 10};
    int array[10] = {1, 3, 5, 6, 234, 9, 3, 2, 4, 20};
    std::vector<bool> boolVector = {true, true, false, false, false, true, false};

    Analyser analyser;
    analyser.printMetrics(intVector);
    analyser.printMetrics(floatVector);

    std::vector<int> vector = analyser.arrayToVector(array);
    analyser.printMetrics(vector);
    analyser.printMetrics(boolVector);


}