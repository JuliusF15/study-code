#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Enter an integer: ");
    scanf("%d", &N);

    
    int *mptr = malloc(sizeof(*mptr)); // Speicher für ein int reservieren
    if (mptr == NULL) {     // Prüfen ob malloc erfolgreich war
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    *mptr = N; // Wert speichern

    int *cptr = calloc(N, sizeof N);
    if (cptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for(int i=0; i<N; i++){
        *(cptr+i) = i*i;
        printf("%d ", cptr[i]);
    }
    printf("\n");
    int *ptemp = realloc(cptr, (N * 2) * sizeof(*cptr));
    if(ptemp == NULL){
        printf("Fehler beim vergrößern des Arrays!");
    }else{
        cptr = ptemp;
        //free(ptemp);
    }
    for(int i=N; i<N*2; i++){
        *(cptr+i) = i*i;
        printf("%d ", cptr[i]);
    }
    for(int i=0; i<N*2; i++){
         printf("%d ", cptr[i]);
     }
    
 
    
    printf("\nStored value: %d\n", *mptr);

    // Speicher freigeben
    free(mptr);
    free(cptr);

    return 0;
}