# include "Products.hpp"

void Product::createProductReport(){
    std::cout << "Product:" << name << std::endl;
    for(int i=0; i<ResultsVec.size(); i++){
        std::cout << ResultsVec[i].InspectionName << ":" << ResultsVec[i].status << std::endl;
    }
}