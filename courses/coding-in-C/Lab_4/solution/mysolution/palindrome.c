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
    char text[101];
    printf("\nGive me a Word. Max. 100 Characters: ");
    if(!fgets(text, sizeof(text), stdin)){
        printf("Wrong input!");
    }else{
        text[strcspn(text, "\n")] = '\0';
        if(checkPalindrome(text)){
            printf("\n%s%s", text, " is a Palindrome!");
        }else{
            printf("\n%s%s", text, " is not a Palindrome!");
        }
    }
}