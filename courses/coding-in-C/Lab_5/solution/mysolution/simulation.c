#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int NUM_CELLS = 10;

int moveCells(int *parray){
    srand(time(NULL));
    for(int i=0; i<NUM_CELLS; i++){
        if(parray[i] == 1){
            int rand_num = rand() % 10;
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
}

int main(){
    int array[10] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    int *parray = array;
    int i = 0;
    for(int i=0; i<NUM_CELLS; i++){
        printf("%d", array[i]);
    }
    while(1){
        int last_time = clock();
        if(clock() % 1000 == 0 && last_time != clock()){
            moveCells(parray);
            printf("\n");
            for(int i=0; i<NUM_CELLS; i++){
                printf("%d", array[i]);
            }            
        }
    }

}

