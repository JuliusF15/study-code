#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = fopen("exampleText.txt", "r");

    char text[100];
    fgets(text, 100, pfile);
    printf("%s", text);
    fclose(pfile);
}