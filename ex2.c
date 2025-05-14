#include <stdio.h>
#include <stdlib.h>

void interface(); 
void inserir(); 
void deletar(); 
void erro(); 
void imprimir();
int op; 
int dado; 
int pos; 
int count = 11;
int nn;


struct node{
    int dado;
    struct node *prox;
    struct node *prev; 
};

//declarando os nodes
struct node *node0 = NULL;
struct node *node1 = NULL;
struct node *node2 = NULL; 
struct node *node3 = NULL; 
struct node *node4 = NULL; 
struct node *node5 = NULL; 
struct node *node6 = NULL;
struct node *node7 = NULL;
struct node *node8 = NULL; 
struct node *node9 = NULL; 
struct node *node10 = NULL; 
struct node *head = NULL; 
struct node *atual = NULL;
struct node *delete = NULL; 
struct node *aux = NULL; 

int main(){

    
    //atribuinado valores para os nodes e alocando na memória 
    node0 = (struct node*) malloc(sizeof(struct node));
    node0 -> dado = 1;
    node1 = (struct node*) malloc(sizeof(struct node));
    node1 -> dado = 2;
    node2 = (struct node*) malloc(sizeof(struct node));
    node2 -> dado = 3; 
    node3 = (struct node*) malloc(sizeof(struct node));
    node3 -> dado = 4; 
    node4 = (struct node*) malloc(sizeof(struct node));
    node4 -> dado = 5; 
    node5 = (struct node*) malloc(sizeof(struct node));
    node5 -> dado = 6;
    node6 = (struct node*) malloc(sizeof(struct node));
    node6 -> dado = 7;
    node7 = (struct node*) malloc(sizeof(struct node));
    node7 -> dado = 8;
    node8 = (struct node*) malloc(sizeof(struct node));
    node8 -> dado = 9; 
    node9 = (struct node*) malloc(sizeof(struct node));
    node9 -> dado = 10; 
    node10 = (struct node*) malloc(sizeof(struct node));
    node10 -> dado = 11; 
    head = node0;
    atual = head;

    //"encadeando" a lista
    head = node0;

    node0 -> prox = node1; 
    node0 -> prev = NULL; 

    node1 -> prox = node2; 
    node1 -> prev = node0;

    node2 -> prox = node3;
    node2 -> prev = node1;
    
    node3 -> prox = node4;
    node3 -> prev = node2;
    
    node4 -> prox = node5;
    node4 -> prev = node3; 
    
    node5 -> prox = node6;
    node5 -> prev = node4; 
    
    node6 -> prox = node7;
    node6 -> prev = node5; 
    
    node7 -> prox = node8;
    node7 -> prev = node6;
    
    node8 -> prox = node9;
    node8 -> prev = node7;

    node9 -> prox = node10;
    node9 -> prev = node8;
    
    node10 -> prox = NULL; 
    node10 -> prev = node9; 
    
    imprimir(); 
    interface();

    return 0;
}

void interface(){
    printf("Digite:\n 1) Para inserir um novo elemento\n 2) Para deletar um determinado elemento\n 3) Para encerrar o programa\n");
    scanf("%d", &op);
    if(op == 1){
        inserir();
    }
    else if(op == 3){
        exit(1);
    }
    else if(op == 2){
        deletar(); 
    }
    else{
        erro(); 
    }
}

void inserir(){
    printf("Quantos nodos você deseja inserir?\n ");
    scanf("%d", &nn);
    int i = 0; 
    while(i < nn){
    
        struct node *novo = NULL; 
        novo = (struct node*) malloc(sizeof(struct node));
        atual = head;  
        printf("Digite o dado que você deseja inserir na lista encadeada:");
        scanf("%d", &dado); 
        printf("Digite a posição em que deseja inserir esse dado: ");
        scanf("%d", &pos);
        novo -> dado = dado;
        if(pos == 0){
            novo -> prox = head; 
            novo -> prev = NULL;
            head -> prev = novo;
            head = novo; 
        }else{
            for(int i = 0; i < pos - 1 && atual -> prox != NULL; i++){
            atual = atual -> prox; 
        }
            if(pos == count){
                atual -> prox = novo; 
                novo -> prev = atual; 
                novo -> prox = NULL;
            }else{
                aux = atual -> prox; 
                novo -> prox = atual -> prox; 
                atual -> prox = novo; 
                novo -> prev = atual; 
                aux -> prev = novo;
            }
        }

        atual = head; 
        while(atual != NULL){
            printf("%d\n", atual -> dado);
            atual = atual -> prox;
        }
        i++;
        count++;
    }
     imprimir();
}

void deletar(){
    printf("Quantos nodos você deseja deletar?\n");
    scanf("%d", &nn);
    int i = 0; 
    while(i < nn){
        atual = head; 
        printf("Digite a posição do nodo que você deseja deletar: ");
        scanf("%d", &pos); 
    
        if(pos == 0){
            head = atual -> prox;
            free(atual);
            head -> prev = NULL;
        }else{
            for (int i = 0; i < pos - 1; i++) {
            atual = atual -> prox;
            }    
            delete = atual -> prox; 
      
            if(pos == count - 1){
                atual -> prox = NULL;
            }else{
                aux = delete -> prox;
                atual -> prox = delete -> prox; 
                aux -> prev = atual; 
            }
       
            free(delete); 
        }
            atual = head; 
            while(atual != NULL){
                 printf("%d\n", atual -> dado);
                 atual = atual -> prox;
            }
        i++;
        count --;
    }
    
    
    imprimir(); 

}

void erro(){
    printf("O valor digitado é inválido. Digite:\n 1) Para inserir um novo elemento\n 2) Para deletar um determinado elemento");
    scanf("%d", &op);
    if(op == 1){
        inserir();
    }
    else if(op == 2){
        deletar(); 
    }
    else{
        erro(); 
    }
}

void imprimir(){
    atual = head; 
    while(atual != NULL){
        printf("%d\n", atual -> dado);
        atual = atual -> prox;
    }
    interface(); 
}

