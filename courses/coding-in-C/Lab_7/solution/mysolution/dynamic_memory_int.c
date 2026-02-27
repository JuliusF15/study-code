#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Enter an integer: ");
    if (scanf("%d", &N) != 1){
        printf("\nError");
        return 1;
    }

    
    int *mptr = malloc(sizeof(*mptr)); // Speicher für ein int reservieren; malloc braucht die Größe in Bits die er freigeben soll; Void pointer hat kein Datentyp kann also auf alle variablentypen zeigen
    if (mptr == NULL) {     // Prüfen ob malloc erfolgreich war, wenn nicht gibt es immer NULL zurück (calloc und realloc auch)
        printf("\nMemory allocation failed.");
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
    int *ptemp = realloc(cptr, (N * 2) * sizeof(*cptr)); //auch hier muss eine byte Anzahl als Größe angegeben werden
    if(ptemp == NULL){
        printf("Fehler beim vergrößern des Arrays!");
    }else{
        cptr = ptemp; //hier temporäres Array benutzen, da bei einem Fehler vorher das alte array cptr mit NULL überchrieben werden würde
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
    mptr = NULL;
    cptr = NULL; //um dangling pointer zu verhindern

    return 0;
}