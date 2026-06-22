#include "greenhouse.hpp"

Sensor::Sensor(std::string name, float minValue, float maxValue): sensorName(name), MIN_VALUE(minValue), MAX_VALUE(maxValue){
    if(minValue > maxValue || minValue == maxValue){
        throw std::invalid_argument("Invalid Configuration");
    }
};

void Sensor::updateValue(double value){
        if(value > MIN_VALUE && value < MAX_VALUE){
            this->value = value;
            return;
        }else{
            throw std::out_of_range("out of range");
            return;
        }
}

int Sensor::getValue(){
    return value;
}

void Sensor::printInfo(){
    std::cout << "Value: " << value << std::endl;
}

void Sensor::simulate_failure(){
    throw SensorFailureError();
}