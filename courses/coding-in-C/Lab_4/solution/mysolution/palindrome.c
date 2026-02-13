#include <stdio.h>
#include <string.h>

int checkPalindrome(char string[]){
    char *pstring = string;
    for(int i=0; i<strlen(string)/2; i++){
        if(*(pstring+i) == *(pstring + (strlen(string)-i-1)) || 
        (*(pstring+i)-32) == (*(pstring + (strlen(string)-i-1))) || 
        *(pstring+i) == (*(pstring + (strlen(string)-i-1))-32)){
            NULL;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    char text[100];
    printf("\nGive me a Word. Max. 100 Characters: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    int check = checkPalindrome(text);
    if(check == 0){
        printf("\n%s%s", text, " is not a Palindrome!");
    }else{
        printf("\n%s%s", text, " is a Palindrome!");
    }
}