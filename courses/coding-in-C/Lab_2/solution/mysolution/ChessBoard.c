#include <stdio.h>

int numRows = 8;
int numCols = 8;

int main(){
    for(int i=numRows; i>0; i--){
        for(int e=0; e<numCols; e++){
            printf("%c", 65+e); //Print Letter using ASCII of A plus the current Collumn
            printf("%d %c", i, " "); //Print Number using current Row

        }
        printf("\n");
        printf("\n");
    }
}