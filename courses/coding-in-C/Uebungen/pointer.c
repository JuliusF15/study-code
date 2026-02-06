#include <stdio.h>

int main(){
    int myNumbers[5] = {10,20,30,40,50};
    int *pNum = myNumbers;
    int length = sizeof(myNumbers)/sizeof(int);

    printf("Zweite Element: %d Adresse: %d", *(pNum+1), pNum+1);
    printf("\nLetzte Elemet: %d Adresse: %d", *(pNum+length-1), pNum+length-1);
    printf("\nDifferenz: %d", pNum+1 - pNum+length-1);
}
