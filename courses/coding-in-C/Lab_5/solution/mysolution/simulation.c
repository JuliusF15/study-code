#include<time.h>
#include<stdio.h>

int sim(int i){
    printf("\n%d", i);
}
int main(){
    int array[10] = {0, 0, 1, 0, 1, 0, 1, 0, 0, 0};
   // int temp_array[sizeof(array)] = array;
    //int *ptemp_array = temp_array;
    int *parray = array;
    int i = 0;
    while(1){
        int last_time = clock();
        if(clock() % 1000 == 0 && last_time != clock()){
            sim(i);

            i++;
        }
    }

}

