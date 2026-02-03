#include <stdio.h>

int numRows = 8;
int numCols = 8;

int main(){
    for(int i=0; i<numRows; i++){
        for(int e=0; e<numCols; e++){
            printf("%c", 65+e); //Print Letter
            printf("%d %c", numRows-i, " ");

        }
        printf("\n");
        printf("\n");
    }
}