#include <stdlib.h>
#include <stdio.h>
struct SensorData{
    float time;
    double probability;

};

struct Sensor{
    int id;
    double threshold;
    struct SensorData data[3000];
    int object_detection[3000];
};

void read_file(struct Sensor *Sensor, struct SensorData *SensorData){
    int file_num = Sensor->id;
    double threshold = Sensor->threshold;

    char filename[100];

    snprintf(filename, sizeof(filename),
             "sensor%d.txt",
             file_num);

    FILE *pfile = fopen(filename, "r");

    if (pfile == NULL) {
        printf("Datei konnte nicht geöffnet werden.\n");
        return;
    }

    char text[10];
    double time, prob;
    int counter = 0;
    while (fgets(text, sizeof(text), pfile) != NULL) {
        if (sscanf(text, "%lf %lf", &time, &prob) == 2) { //liest genau die datentypen die man ihm gibt aus
            SensorData->probability = prob;
            SensorData->time = time;
            Sensor->data[counter] = *SensorData;
            if(prob >= threshold){
                Sensor->object_detection[counter] = 1;
            }else{
                Sensor->object_detection[counter] = 0;
            }
            counter++;
        }
    }
}

void analyse_file(struct Sensor *Sensor, float Intervall[]){
    int array_pos = 0;

    for(int i=0; i<3000; i++){
        if(Sensor->object_detection[i] == 1 && Sensor->object_detection[i-1] == 0){
            Intervall[array_pos] = Sensor->data[i].time;
            array_pos++;
        }   
        if(Sensor->object_detection[i] == 0 && Sensor->object_detection[i-1] == 1){
            Intervall[array_pos] = Sensor->data[i].time;
            array_pos++;
        }
    }
}

void check_overlap(struct Sensor *Sensor1, struct Sensor *Sensor2, float *overlap){
    int o_counter = 0;
    int overlapping = 0;
    for(int i=0; i<3000; i++){
        if(Sensor1->object_detection[i] == 1 && Sensor2->object_detection[i] == 1
        && (Sensor1->object_detection[i-1] == 0 || Sensor2->object_detection[i-1] == 0) && overlapping == 0){
            overlap[o_counter] = Sensor1->data[i].time;
            o_counter++;
            overlapping = 1;
        }
        if((Sensor1->object_detection[i] == 0 && Sensor1->object_detection[i-1] == 1
        || Sensor2->object_detection[i] == 0 && Sensor2->object_detection[i-1] == 1) && overlapping == 1){
            overlap[o_counter] = Sensor1->data[i].time;
            o_counter++;
            overlapping = 0;
        }
    }
}

int main(){
    double THRESHOLD_S1 = 0.8;
    double THRESHOLD_S2 = 0.7;

    struct Sensor Sensor1 = {1, THRESHOLD_S1};
    struct Sensor Sensor2 = {2, THRESHOLD_S2};

    struct SensorData SensorData1 = {};
    struct SensorData SensorData2 = {};
    
    read_file(&Sensor1, &SensorData1);
    read_file(&Sensor2, &SensorData2);

    float Intervall_Sensor_1[20];
    float Intervall_Sensor_2[20];
    float overlap[20];

    analyse_file(&Sensor1, Intervall_Sensor_1);
    analyse_file(&Sensor2, Intervall_Sensor_2);

    check_overlap(&Sensor1, &Sensor2, overlap);
    for(int i=0; i<20; i=i+2){
        if(Intervall_Sensor_1[i] != 0){
            printf("\nIntervall S1: %f - %f", Intervall_Sensor_1[i], Intervall_Sensor_1[i+1]);
        }
        if(Intervall_Sensor_2[i] != 0){
            printf("\nIntervall S2: %f - %f", Intervall_Sensor_2[i], Intervall_Sensor_2[i+1]);
        }
        if(overlap[i] != 0){
            printf("\nOverlap: %f - %f", overlap[i], overlap[i+1]);
        }
    }
    /*for(int i=0; i<3000; i++){
        printf("\nSensor 1: Time:%lf Probability:%lf Detect: %d",Sensor1.data[i].time ,Sensor1.data[i].probability, Sensor1.object_detection[i]);
        printf("\nSensor 2: Time:%lf Probability:%lf Detect: %d\n",Sensor2.data[i].time ,Sensor2.data[i].probability, Sensor2.object_detection[i]);
    }*/
    
}