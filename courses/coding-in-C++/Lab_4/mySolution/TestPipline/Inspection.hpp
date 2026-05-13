#include <iostream>
#include <string>
#include "Products.hpp"

class Inspection{
    protected:
        std::string InspectionType;
        static bool successOfLastInspection;
        static int totalSuccessCounter;
        static int totalInspection;

    public:
        Inspection(std::string Type): InspectionType(Type){};
        virtual ~Inspection();

        void createInspectionReport() const{
            std::cout << "Inspection Type: " << this->InspectionType << std::endl;
            if(this->successOfLastInspection){
                std::cout << "Last Inspection was successfull" << std::endl;
            }else{
                std::cout << "Last Inspection was not successfull" << std::endl;
            }
            std::cout << "Successrate: " << this->totalInspection << "/" << this->totalSuccessCounter << std::endl;
        }   
};
int Inspection::totalSuccessCounter = 0;
int Inspection::totalInspection = 0;
bool Inspection::successOfLastInspection = false;

class WeightCheck: public Inspection{
    protected:
        static constexpr int MAX_WEIGHT = 1000;
        static constexpr int MIN_WEIGHT = 50;
    public:
        WeightCheck(): Inspection("Weight Check"){};

        void CheckWeight(Product &product);


};
class TempCheck: public Inspection{
    protected:
        static constexpr int MAX_TEMP = 1000;
        static constexpr int MIN_TEMP = 50;
    public:
        TempCheck(): Inspection("Temperature Check"){};

        void CheckTemp(const Product &product);


};
class VoltCheck: public Inspection{
    protected:
        static constexpr int MAX_VOLT = 1000;
        static constexpr int MIN_VOLT = 50;
    public:
        VoltCheck(): Inspection("Voltage Check"){};

        void CheckVolt(const Product &product);


};
class VisualCheck: public Inspection{
    public:
        VisualCheck(): Inspection("Visual Check"){};

        void CheckVisual(const Product &product);
};