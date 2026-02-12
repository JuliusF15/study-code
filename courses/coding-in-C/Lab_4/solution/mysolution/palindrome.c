#include <stdio.h>
#include <string.h>

int main(){
    char text[10];
    char *ptext = text;
    printf("\nGive me a Word. Max. 100 Characters: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("%s", text);
}