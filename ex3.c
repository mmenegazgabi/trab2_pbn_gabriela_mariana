#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void criar_lista();
void imprimir(); 
void imprimir_t_p();
struct node *aux = NULL;
struct node *head = NULL;
struct node *tail = NULL;


struct node{
    int dado; 
    struct node *prev; 
    struct node *next; 
}; 


int main(){
    srand(time(0)); 
    criar_lista();
    imprimir(); 
    imprimir_t_p();
    return 0; 
}



void criar_lista(){
    head = (struct node*) malloc(sizeof(struct node)); 
    head -> dado = (rand() % 150); 
    aux = head; 
    for(int i = 0; i < 49; i++){
        struct node *novo = NULL;
        novo = (struct node*) malloc(sizeof(struct node));
        novo -> dado = (rand() % 150); 
        novo -> prev = aux; 
        aux -> next = novo; 
        aux = aux -> next; 
    }
    
    tail = aux;
    tail -> next = head;
    head -> prev = tail;
    
}


void imprimir(){
    aux = head; 
    int i = 0; 
    printf("Liste impressa começando do começo:\n");
    while(aux != NULL && i != 50){
        printf("%d\n", aux -> dado);
        aux = aux -> next;
        i++; 
    }
}

void imprimir_t_p(){
    aux = tail;
    int i = 0; 
    printf("Lista impressa começando do final:\n");
    while(aux != NULL && i != 50){
        printf("%d\n", aux -> dado);
        aux = aux -> prev; 
        i++;
    }
}