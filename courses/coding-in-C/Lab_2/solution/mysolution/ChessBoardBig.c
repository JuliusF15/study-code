#include <stdio.h>

int numRows = 8;
int numCols = 8;

void printColLetters(){
    printf("%c%c%c", 32, 32, 32);
    for(int e=0; e<numCols; e++){
        printf("%c%c%c%c", 32, 65+e, 32, 32); //Print Letter
    }
}
void printLine(){
    printf("\n");
    printf("%c ", 32);
    for(int i=0; i<numCols;i++){
        printf("%c", 43);
        printf("%c" "---");
    }
    printf("%c", 43);

}
void printRows(){
    printf("\n");
    for(int i=numRows; i>0; i--){
        printf("%d ", i);
        printf("%c", 124);
    
        for(int e=0; e<numCols;e++){
            if((i+e)%2==0){
                printf("%c%c%c", 35, 35, 35);
            }else{
                printf("%c%c%c", 32, 32, 32);
            }
            printf("%c", 124);
        }
        printf(" %d", i);
        printLine();
        printf("\n");
    }
}

int main(){
    printColLetters();
    printLine();
    printRows();
    printColLetters();
}
