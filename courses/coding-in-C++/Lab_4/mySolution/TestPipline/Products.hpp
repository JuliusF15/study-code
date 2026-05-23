#include <iostream>
#include <string>
#include <vector>

struct InspectionResults{
    std::string InspectionName;
    bool status;
};

class Product{
    protected:
        std::string name;
        int ID;
        int weight;
        bool visualDefectStatus;
        std::vector<InspectionResults> ResultsVec;
    
    public:
        Product(std::string name, int ID, int weight, bool visualDefect): name(name), ID(ID), weight(weight), visualDefectStatus(visualDefect){};
        virtual ~Product();

        void createProductReport(); 

        void addInspectionResult(std::string name, bool status){
            InspectionResults Result;
            Result.InspectionName = name;
            Result.status = status;
            ResultsVec.push_back(Result);
        }
        void addInspectionResult(InspectionResults Result){
            ResultsVec.push_back(Result);
        }

        std::string getName() const{
            return this->name;
        }
        int getWeight() const{
            return this->weight;
        }
        bool getVisDefStat() const{
            return this->visualDefectStatus;
        }

        
};

class CombustionEngine: public Product{
    protected:
        int temperature;
    public:
        CombustionEngine(int temperature):Product(), temperature(temperature){};
};