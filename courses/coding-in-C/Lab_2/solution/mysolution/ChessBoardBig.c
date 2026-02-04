#include <stdio.h>

int NUMROWS = 8;
int NUMCOLS = 8;

void printColLetters(){
    printf("%c%c%c", 32, 32, 32);
    for(int e=0; e<NUMCOLS; e++){
        printf("%c%c%c%c", 32, 65+e, 32, 32); //Print Letter
    }
}
void printLine(){
    printf("\n");
    printf("%c ", 32);
    for(int i=0; i<NUMCOLS;i++){
        printf("%c", 43);
        printf("%c" "---");
    }
    printf("%c", 43);

}
void printRows(){
    printf("\n");
    for(int i=NUMROWS; i>0; i--){
        printf("%d ", i);
        printf("%c", 124);
    
        for(int e=0; e<NUMCOLS;e++){
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
