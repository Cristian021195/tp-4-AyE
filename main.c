#include <stdio.h>
#include <stdlib.h>
#define K -9999

typedef int item;

typedef struct ELEMENTO {
    item dato;
    struct ELEMENTO* siguiente;
}ELEMENTO;

typedef struct ELEMENTO* GRUPO;


GRUPO GRUPOVACIO();
int ESVACIO(GRUPO G);
GRUPO AGREGAR(GRUPO G, item x);
void MOSTRAR(GRUPO G);
GRUPO QUITARULTIMO(GRUPO G);
item ULTIMOELEMENTO(GRUPO G);
int CANTIDAD(GRUPO G);
int INCLUIDO(GRUPO G, item x);
int CONTARCOMUNES(GRUPO G, GRUPO *J);
GRUPO UNION(GRUPO G, GRUPO *J); // como usuario ADT

int main(){
    GRUPO G = GRUPOVACIO();     GRUPO J = GRUPOVACIO();    GRUPO V = GRUPOVACIO();
    printf("Grupo G\n");
    G = AGREGAR(G, 3);  G = AGREGAR(G, 2);
    G = AGREGAR(G, 1); G = AGREGAR(G, 0);
    MOSTRAR(G); 

    printf("Grupo J\n");
    J = AGREGAR(J,9);   J = AGREGAR(J, 7);
    J = AGREGAR(J, 4); J = AGREGAR(J, 3); 
    //BORRARULTIMO(&J);
    MOSTRAR(J);

    if (ESVACIO(V) == 1){   printf("El grupo V es vacio\n");    }
    if (!ESVACIO(J)){   printf("El grupo J No es vacio\n");    }
    
    //printf("union G\n");

    //G = UNION(&G, J);
    //MOSTRAR(UNION(G,&J));
    if (!ESVACIO(J)){   printf("El grupo J No es vacio\n");    }

	//MOSTRAR(J);
    //printf("---\n");
    //MOSTRAR(G);
    //printf("---\n");
    //MOSTRAR(J);
    printf("\nCOMUNES: %d\n", CONTARCOMUNES(G,&J));

    
    
}
GRUPO GRUPOVACIO(){
    return NULL;
}
int ESVACIO(GRUPO G){ 
    return G == NULL;// ? 1 : 0;
}
GRUPO AGREGAR(GRUPO G, item x){
    ELEMENTO* nuevo = malloc(sizeof(ELEMENTO));
    nuevo->dato=x;
    nuevo->siguiente = G;
    G = nuevo;
    return G;
}
void MOSTRAR(GRUPO G){
    while (G!=NULL)
    {
        printf("El valor del nodo es: %d\n", G->dato);
        G= G->siguiente;
    }
}
GRUPO QUITARULTIMO(GRUPO G){
    if (G==NULL)
    {
        printf("No hay nada por QUITARULTIMO\n");
        return G;
    } else
    {
        ELEMENTO* aux;
        aux = G;
        G = aux->siguiente;
        free(aux);
        return G;
    }
}
item ULTIMOELEMENTO(GRUPO G){
    return G == NULL ? K : G->dato;    
}
int CANTIDAD(GRUPO G){
    int cont = 0;

    while (G!=NULL)
    {
        G = G->siguiente;
        cont++;
    }
    return cont;
}
int INCLUIDO(GRUPO G, item x){
    while (G!=NULL)
    {
        if(x==G->dato){
            return 1;
        }
        G=G->siguiente;
    }
    return 0;
}

int CONTARCOMUNES(GRUPO G, GRUPO *J){ // COMO PARTE DEL ADT ACCEDE A PUNTERO Y DEMAS (A DIFERENCIA DE UNION)
    int contador = 0;
    ELEMENTO *AUX = *J;

	while (G!=NULL && *J!=NULL){
    	if( G->dato == (*J)->dato){
	        contador++;
            *J = (*J)->siguiente;
            free(AUX);
    	}
    	G=G->siguiente;
    }
    return contador;
}

GRUPO UNION(GRUPO G, GRUPO *J){ // COMO USUARIO, IMPLEMENTAMOS LAS FUNCIONES YA ANTERIORMENTE DEFINIDAS EN LA ESPECIFICACION
    if(ESVACIO(*J)){
        return G;    
    }else{
    	item dato=ULTIMOELEMENTO(*J);
    	*J = QUITARULTIMO(*J);
        return AGREGAR(UNION(G, J), dato);
    }
}