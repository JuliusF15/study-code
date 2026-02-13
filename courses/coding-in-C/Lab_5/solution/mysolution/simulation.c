#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int NUM_CELLS = 20;

int moveCells(int *parray, int *temp_array){
    srand(time(NULL));
    for(int i=0; i<NUM_CELLS; i++){
        int rand_num = rand() % 10;
        if(parray[i] == 1){
            if(rand_num < 5 && i != 0){
                if(parray[i-1] == 0){
                    parray[i] = 0;
                    parray[i-1] = 1;
                }else{
                    printf("\nCollision in Cell: %d", i-1);
                    parray[i] = 0;
                    parray[i-1] = 0;
                }
            }else if(rand_num > 5 && i != 10){
                if(parray[i+1] == 0){
                    parray[i] = 0;
                    parray[i+1] = 1;
                }else{
                    printf("\nCollision in Cell: %d", i+1);
                    parray[i] = 0;
                    parray[i+1] = 0;
                }
            }
        }
    }
    /*for(int i=0; i<NUM_CELLS; i++){
        parray[i] = temp_array[i];
    }*/
   
}

int sim(int *parray){
    int temp_array[NUM_CELLS] = {};
    int *ptemp_array = temp_array;
    for(int i=0; i<NUM_CELLS; i++){
        temp_array[i] = parray[i];
    }
    moveCells(parray, temp_array);

}
int main(){
    int array[20] = {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0};
    int i = 0;
    for(int i=0; i<NUM_CELLS; i++){
        printf("%d", array[i]);
    }
    while(1){
        int last_time = clock();
        if(clock() % 1000 == 0 && last_time != clock()){
            sim(array);
            printf("\n");
            for(int i=0; i<NUM_CELLS; i++){
                printf("%d", array[i]);
            }
            
        }
    }

}

