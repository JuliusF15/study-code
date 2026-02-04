#include <stdio.h>


int main(){
    float Input1;
    float Input2;
    float Output;
    char Operation;
    while(1){

        printf("\nPress Strg+C to Exit...");
        printf("\nNumber1: ");
        scanf("%f", &Input1);
        printf("\nNumber2: ");
        scanf("%f", &Input2);

        printf("\nChoose Operation(+, -, *, /): ");
        scanf(" %c", &Operation);

        if(Operation == '+'){
            Output = Input1 + Input2;
            printf("%f", Output);
        }else if(Operation == '-'){
            Output = Input1 - Input2;
            printf("%f", Output);     
        }else if(Operation == '*'){
            Output = Input1 * Input2;
            printf("%f", Output);     
        }else if(Operation == '/'){
            if(Input2 == 0){
                printf("Can't divide with 0");
                break;
            }else{
                Output = Input1 / Input2;
                printf("%f", Output);
            }
        }else{
            printf("\nNot a Valid Operation!");

        }

    }

}