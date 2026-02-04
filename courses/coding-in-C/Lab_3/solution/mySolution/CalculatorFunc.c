#include <stdio.h>

float add(float input1, float input2);
float subtract(float input1, float input2);
float multiply(float input1, float input2);
float divide(float input1, float input2);

int main(){

    float input1;
    float input2;
    float Output;
    char Operation;

    while(1){

        printf("\nPress Strg+C to Exit...");
        printf("\nNumber1: ");
        scanf("%f", &input1);
        printf("\nNumber2: ");
        scanf("%f", &input2);

        printf("\nChoose Operation(+, -, *, /): ");
        scanf(" %c", &Operation);

        switch (Operation)
        {
        case '+': // +
            Output = add(input1, input2);
            printf("%f", Output);
            break;
        case '-': // -
            Output = subtract(input1, input2);
            printf("%f", Output);        
            break;
        case '*': //*
            Output = multiply(input1, input2);
            printf("%f", Output);         
            break;
        case '/': // /
            Output = divide(input1, input2);
            printf("%f", Output);
            break;
        default:
            printf("\nNot a Valid Operation!");
            break;
        }
    }

}

float add(float input1, float input2){
    float Output = input1 + input2;
    return Output;
}
float subtract(float input1, float input2){
    float Output = input1 - input2;
    return Output;
}
float multiply(float input1, float input2){
    float Output = input1 * input2;
    return Output;
}
float divide(float input1, float input2){
    if(input2 == 0){
        printf("Can't divide with ");
        return 0;
    }else{
       float Output = input1 / input2;
       return Output;
        }
}


