#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <string>
#include <vector>


class Analyser{
    protected:

    public:
        template <typename T>
        T sumOfAllValues(std::vector<T> &vector) const{
            T sum = 0;
            for(auto i : vector){
                sum += i;
            }
            return sum;
        }

        template <typename T>
        T largestValue(std::vector<T> &vector) const{
            T max = *vector.begin();
            for(auto i : vector){
                if(i>max){
                    max = i;
                }
            }
            return max;
        }
        template <typename T>
        T smallestValue(std::vector<T> &vector) const{
            T min = *vector.begin();
            for(auto i : vector){
                if(i<min){
                    min = i;
                }
            }
            return min;
        }

        template <typename T>
        void printMetrics(std::vector<T> &vector) const{
            T maxValue = largestValue(vector);
            T minValue = smallestValue(vector);
            T sumValue = sumOfAllValues(vector);

            std::cout << "Sum: " << sumValue << " Max: " << maxValue << " Min: " << minValue << std::endl;
        }

        template <typename T, int N>
        std::vector<T> arrayToVector(const T(&array)[N]){
            std::vector<T> vector;
            for(int i=0; i<N; i++){
                vector.push_back(array[i]);
            }
            return vector;
        }

};

template <>
void Analyser::printMetrics<bool>(std::vector<bool> &vector) const{
    float counter = 0;
    for(auto i: vector){
        if(i == true){
            counter++;
        }
    }
    if(counter >= float(vector.size())/2){
        std::cout << "More than half are true" << std::endl;
        return;
    }
    std::cout << "Less than half are true" << std::endl;

}

#endif