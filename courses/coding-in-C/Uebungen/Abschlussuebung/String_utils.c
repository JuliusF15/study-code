#include <stdio.h>
#include <stdlib.h>

int custom_len(char string[]){
    int counter = 1;
    while(*(string+counter) != '\0'){
        counter++;
    }
    return counter;
}

void read_line_dynamic(char **string){
    char text[100];
    printf("Input String: ");
    fgets(text, sizeof(text), stdin);
    int length = custom_len(text);
    *string = malloc(length);
    
}
int main(){
    int c = custom_len("acc");
    printf("%d", c);
    char *string;
    read_line_dynamic(&string);
    printf("Text: %s", string);

}