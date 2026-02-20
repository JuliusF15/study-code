#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double data;
    struct Node *pnext;
}Node;

Node *create_Node(double data){
    Node *newnode = malloc(sizeof(Node));
     if(newnode == NULL){
        printf("Fehler bei der Speicherfreigabe");
    }
    newnode->data = data;
    newnode->pnext= NULL;
    return newnode;
}

void insert_Node(Node *New_Node, Node *head, int index){ 
    if(index == 0){
        New_Node->pnext = head;
        head = New_Node;
    }else{
        Node *current = NULL;
        current = head;
        for(int i=0; i<index-1; i++){
            current = current->pnext;
        }
        New_Node->pnext = current->pnext;
        current->pnext = New_Node;
    }

}
void delete_List(Node *head){
    while(head->pnext != NULL){
        Node *tmp = head->pnext;
        head = head->pnext;
        free(tmp);
    }
}
int main(){
    Node *current = NULL;
    Node *head = NULL;
    for(int i=0; i<50; i++){
        Node *newNode;
        newNode = create_Node(i);
        if (head == NULL) {
            head = newNode;      // Head wird durch die erste Node ersetzt. Da es nur eine gibt, ist current diese Node
            current = head;
        }else {
        current->pnext = newNode; //im bei der 2. Node wird der pnext vom Head auf diesen gelegt, dann wandert current zum nächsten. Bei der 3. Node wird der pnext von der 2.Node auf die Adresse der 3. gesetzt, da current == Node2 ist
        current = newNode;
        }
    }
    Node *newNode;
    newNode = create_Node(10);
    insert_Node(newNode, head, 3);
    newNode = create_Node(20);
    insert_Node(newNode, head, 5);
    newNode = create_Node(30);
    insert_Node(newNode, head, 7);

    printf("%lf", head->data);

    delete_List(head);
    printf("HHHH");
}