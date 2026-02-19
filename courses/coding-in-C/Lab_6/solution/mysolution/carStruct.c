#include <stdlib.h>
#include <stdio.h>

struct carStruct
{
    float fuel_lvl;
    float max_fuel_lvl;
    char model[50];
};
void refuel(struct carStruct *car, float fuel){
    if(car->max_fuel_lvl >= car->fuel_lvl+fuel){
        car->fuel_lvl = car->fuel_lvl+fuel;
    }else{
        printf("Car to Full!");
    }
}
int main(){
    struct carStruct car1 = {(float)20, (float)100, "BMW"};
    
    printf("\n%.2f", car1.fuel_lvl);
    refuel(&car1, (float)20);
    printf("\n%.2f", car1.fuel_lvl);

    
}