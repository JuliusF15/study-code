#include <stdio.h>


int main(){
    float Input1;
    float Input2;
    float Output;
    char Operation;

    printf("Number1: ");
    scanf("%f", &Input1);
    printf("\nNumber2: ");
    scanf("%f", &Input2);

    printf("\nChoose Operation(+, -, *, /): ");
    scanf(" %c", &Operation);

    switch (Operation)
    {
    case '+': // +
        Output = Input1 + Input2;
        printf("%f", Output);
        break;
    case '-': // -
        Output = Input1 - Input2;
        printf("%f", Output);        break;
    case '*': //*
        Output = Input1 * Input2;
        printf("%f", Output);         break;
    case '/': // /
        Output = Input1 / Input2;
        printf("%f", Output);
        break;
    default:
        printf("\nNot a Valid Operation!");
        break;
    }

}