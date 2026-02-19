#include <stdlib.h>
#include <stdio.h>

void read_file(struct Sensor *Sensor, int file_num){
    char filename[100];

    snprintf(filename, sizeof(filename),
             "courses\\coding-in-C\\Lab_6\\sensor%d.txt",
             file_num);

    FILE *pfile = fopen(filename, "r");

    if (pfile == NULL) {
        printf("Datei konnte nicht geöffnet werden.\n");
        return 1;
    }

    for(int i=0; i<=3000; i++){
        fgets();
    }

}
int main(){
    int THRESHOLD_S1 = 0.8;
    int THRESHOLD_S2 = 0.7;

    struct SensorData{
        float time;
        double probability;

    };

    struct Sensor{
        int id;
        double threshold;
        float data[3000];
        int object_detection[3000];
    };

    struct Sensor Sensor1 = {};
    struct Sensor Sensor2 = {};

    
}