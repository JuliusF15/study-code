#include "greenhouse.hpp"

int main(){
    
    try{
        Sensor tempSensor("Temperatur Sensor", -273.15, 1000);
        Sensor humiditySensor("Humidity Sensor", 0, 100);
        tempSensor.updateValue(100);
        humiditySensor.updateValue(10);
        tempSensor.simulate_failure();
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;

    }
    /*catch(const std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }*/
}