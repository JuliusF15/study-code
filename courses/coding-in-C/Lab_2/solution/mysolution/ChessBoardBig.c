#include <stdio.h>

int numRows = 8;
int numCols = 8;

void printLine(){
    printf("\n");
    for(int i=0; i<numCols;i++){
        printf("%c", "+");
        printf("%c" "---");
        printf("%c", "+");
    }
}

int main(){
    for(int e=0; e<numCols; e++){
        printf("%c %c %c", " ", 65+e, " "); //Print Letter
    }
    printLine();

}

/*
#include <stdio.h>

int numRows = 8;
int numCols = 8;

void printLine(){
    //printf("\n");
    for(int i=0; i<numCols;i++){
        printf("%c" "+---");
    }
    printf("%c" "+");    
    //printf("\n");
}
int main(){
    for(int e=0; e<numCols; e++){
        printf("%c %c %c", " ", 65+e, " "); //Print Letter
    }
    printf("\n");
    printf("\n");
    printLine();

}*/