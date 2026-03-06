#include <stdlib.h>

typedef struct vehicle
{
    int vehicle_id; //unique identifier for the vehicle
    int remaining_parktime; //this is specified by the instructions but actually it's redundant information because we can calculate this from
    int time_of_entry; //time of entry into the parking lot is used to calculate the remaining parking time
    int time_of_arrival; // Us used to calculate the waiting time in the queue
    int random_park_duration; // between 1 and max_parking_time
}vehicle;


vehicle **init(int Anzahl_Parkplätze){
    vehicle **pParkhaus = calloc(Anzahl_Parkplätze+1, sizeof(struct vehicle*)); //    CREATE *pArray TYPE *struct vehicle SIZE Anzahl_Parkplätze + 1 
    if(pParkhaus == NULL){
        return -1;
    }
    vehicle *End_Point = malloc(sizeof(vehicle));
    if(End_Point == NULL){
        return -1;
    }
    End_Point->vehicle_id = -1; // CREATE struct vehicle with vehicle_id of -1 and name "End_Point"
    pParkhaus[Anzahl_Parkplätze] = End_Point;//save "End_Point" at the last Index of pParkhaus 
    return pParkhaus;

}

int isFull(const vehicle *pParkhaus[]){
    int i = 0;
    while(pParkhaus[i]->vehicle_id != -1 || pParkhaus[i] == NULL){//checks if the variable saved at Index[i] is not the End_Point or is NULL 
        if(pParkhaus[i] == NULL){ //check if no Car is present 
            return -1;       //if one is NULL then it is not full
        }   
        i++;
    }

    return 0;  //if no NULL was found then it is full
}

int main(){
    vehicle **parkhaus = init(20);
    printf("&d", isFull(*parkhaus));
}