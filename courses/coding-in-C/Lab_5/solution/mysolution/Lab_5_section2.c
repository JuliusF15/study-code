#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
    for(int i=0; i<argc; i++){
        printf("\nArgument %d at Address %X has content: %s (length: %d)", i, argv[i], argv[i], strlen(argv[i]));
    }
}

//Argument 0 at address "000001A174C03D00" has 
//content: C:\Users\Braunagel\Projects\Lab_5\solution\args.exe (length: 51)
