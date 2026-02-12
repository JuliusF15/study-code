#include <stdio.h>

void changeStr(char string[]){
    char *pstring = string;
    *(pstring+1)= 'c';
}

int main(){
    char text[] = "Curly bird catches the worm";
    char text2[] = "AAtions speak louder than words";
    char *ptext = text;
    char *ptext2 = text2;

    printf("\nPointer Text: %s", ptext);
    *ptext = 'E';
    *(ptext+1) = 'a';
    printf("\nPointer Text: %s", ptext);
    printf("\nPointer Text: %s", ptext2);
    changeStr(ptext2);
    printf("\nPointer Text: %s", ptext2);
    
}
