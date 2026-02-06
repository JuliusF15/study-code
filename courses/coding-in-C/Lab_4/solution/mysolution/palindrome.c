#include <stdio.h>

int main(){
    char text[28] = "Curly bird catches the worm";
    char *ptext = text;
    printf("Text: %s", text);

    printf("\nPointer Text: %s", ptext);
}