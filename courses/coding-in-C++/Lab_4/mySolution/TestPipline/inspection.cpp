#include "Inspection.hpp"

void WeightCheck::CheckWeight(Product &product){
    InspectionResults Results;
    Results.InspectionName = "Weight Check";
    totalInspection++;
    if(product.getWeight() <= MAX_WEIGHT && product.getWeight() >= MIN_WEIGHT){
        Results.status = true;
        successOfLastInspection = true;
        totalSuccessCounter++;
    }else{
        Results.status = false;
        successOfLastInspection = false;

    }
    product.addInspectionResult(Results);
}