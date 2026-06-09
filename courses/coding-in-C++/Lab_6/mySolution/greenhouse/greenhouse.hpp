#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP

#include <iostream>
#include <string>

class SensorFailureError : public std::exception{
    public:
    std::string what(){
        return "Sensor is unreachable";
    }
};

class Sensor{
    private: 
        std::string sensorName;
        double value;
        const float MIN_VALUE; 
        const float MAX_VALUE;
    public: 
        Sensor(std::string name, float minValue, float maxValue);
        void updateValue(double value);
        int getValue();
        void printInfo();
        void simulate_failure();

};


#endif