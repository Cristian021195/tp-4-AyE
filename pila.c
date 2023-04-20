#include <stdio.h>
#include <stdlib.h>

//PRIVADO
typedef int ITEM;

typedef struct ELEMENTO {
    ITEM item;
    struct ELEMENTO * siguiente;
}ELEMENTO;

typedef ELEMENTO * PILA;

//PUBLICO
void PILAVACIA(PILA *P);
void PUSH(PILA *P, ITEM x);
void POP(PILA *P);
void MOSTRAR(PILA P);
int ESPILAVACIA(PILA P);
ITEM TOP(PILA P);

int main(){
    PILA A; PILAVACIA(&A);

    printf("\nES VACIA?: %d", ESPILAVACIA(A));


    PUSH(&A, 3); PUSH(&A, 6); PUSH(&A, 9);

    MOSTRAR(A);

    printf("\nES VACIA?: %d", ESPILAVACIA(A));

    printf("\nTOP: %d", TOP(A));

    printf("\nES VACIA?: %d", ESPILAVACIA(A));

    POP(&A);

    printf("\nTOP: %d", TOP(A));

    MOSTRAR(A);

    return 0;
}


void POP(PILA *P){ // solo guardamos referencia hasta liberarla
    ELEMENTO *N = *P;
    *P = (*P)->siguiente;
    free(N); N = NULL;
}

void PUSH(PILA *P, ITEM x){
    ELEMENTO *N = malloc(sizeof(ELEMENTO));
    N->item = x;
    N->siguiente = *P;
    *P = N;
}
void MOSTRAR(PILA P){
    printf("\n");
    while(P != NULL){
        printf(" [%d]", P->item);
        P = P->siguiente;
    }
}

ITEM TOP(PILA P){
    return P->item;
}

int ESPILAVACIA(PILA P){
    return P == NULL ? 1 : 0;
}

void PILAVACIA(PILA *P){
    *P = NULL;
}