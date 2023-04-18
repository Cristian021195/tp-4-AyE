#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct ELEMENTO{
	int dato;
	struct ELEMENTO *siguiente;
}ELEMENTO;

//funciones
void ESVACIO(ELEMENTO *lista);
ELEMENTO * GRUPOVACIO(ELEMENTO *lista);//funciones de tipo puntero
ELEMENTO * AGREGAR(int valor,ELEMENTO *lista);
ELEMENTO * insertarNodoFinal(int valor,ELEMENTO *lista);
ELEMENTO * retirarNodoInicio(ELEMENTO *lista);
ELEMENTO * QUITARULTIMO(ELEMENTO *lista);
ELEMENTO * primerElemento(ELEMENTO *lista);
ELEMENTO * ULTIMOELEMENTO(ELEMENTO *lista);
ELEMENTO * UNION(ELEMENTO *listaA, ELEMENTO *listaB);
//void logitud(ELEMENTO *lista);
void CANTIDAD(ELEMENTO *lista);
void imprimirLista(ELEMENTO *lista);
int INCLUIDO(ELEMENTO *lista, int num);
 
int main(){
	ELEMENTO *lista, *listaB;
	int cond = 0; int val;
    int longA  = 0; int longB = 0;
	lista = GRUPOVACIO(lista);
    listaB = GRUPOVACIO(listaB);
	
	do{
		printf("\nINSERTAR ELEMENTO A LA LISTA:\n 1 al inicio \n 2 Al final \n 3 ver elementos de lista \n 4 retirar ELEMENTO del comienzo \n 5 retirar ELEMENTO del final: \n 6 Chequear Vacia: \n 7 Primer Elemetno: \n 8 Ultimo Elemetno: \n 9 Longitud Lista: \n 10 Pertenece elemento: \n 11 Agregar a lista B: \n 12 listar B: \n 13 Unir Todo a lista A _ ");
		scanf("%d", &cond);fflush(stdin); 
		
		if(cond == 1){
			system("cls");
			printf("\nIntroduzca el valor a agregar al inicio: ");
			scanf("%d", &val);fflush(stdin);
			lista = AGREGAR(val, lista);
		}else if(cond == 2){
			system("cls");
			printf("\nIntroduzca el valor a agregar al final: ");
			scanf("%d", &val);fflush(stdin);
			lista = insertarNodoFinal(val, lista);
		}else if(cond == 3){
			system("cls");
			imprimirLista(lista);
		}else if(cond == 4){
			system("cls");
			lista = retirarNodoInicio(lista);
		}else if(cond == 5){
			system("cls");
			lista = QUITARULTIMO(lista);
		}else if(cond == 6){
			system("cls");
			ESVACIO(lista);
		}else if(cond == 7){
			system("cls");
			printf("El primer elemento es: %d", primerElemento(lista)->dato); 
		}else if(cond == 8){
			system("cls");
			printf("El ultimo elemento es: %d", ULTIMOELEMENTO(lista)->dato); 
		}else if(cond == 9){
			system("cls");
			CANTIDAD(lista);			
		}else if(cond == 10){
			system("cls");
			printf("\nIntroduzca el valor a consultar: ");
			scanf("%d", &val);fflush(stdin);
			INCLUIDO(lista, val) == 1 ? printf("\nExiste") : printf("\nNo existe");
		}else if(cond == 11){
			system("cls");
			printf("\nIntroduzca el valor a agregar al inicio LB: ");
			scanf("%d", &val);fflush(stdin);
			listaB = AGREGAR(val, listaB);
		}else if(cond == 12){
			system("cls");
			imprimirLista(listaB);
		}else if(cond == 13){
			system("cls");
            imprimirLista(UNION(lista, listaB));
		}

	}while(cond != 14);
	
	imprimirLista(lista);
	
return 0;
}

void ESVACIO(ELEMENTO *lista){
	if(lista == NULL){
		printf("Esta vacia");
	}else{
		printf("Tiene elementos");
	}
}

void CANTIDAD(ELEMENTO *lista){
	int tamanio_nodo = sizeof(ELEMENTO); int contador = 0;
	ELEMENTO *nodoAuxiliar;
	nodoAuxiliar = lista;
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de ELEMENTO aux
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
		contador++;
	}

	printf("El tamanio de la lista es de %d elementos y %d bytes",contador, (tamanio_nodo*contador));
}

int INCLUIDO(ELEMENTO *lista, int num){
	int tamanio_nodo = sizeof(ELEMENTO); int resp = 0;
	ELEMENTO *nodoAuxiliar;
	nodoAuxiliar = lista;
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de ELEMENTO aux
		if(num == nodoAuxiliar->dato){//existe
            return 1;
		}else{
            resp = 0;
		}
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
	}
    return resp;
}

ELEMENTO *GRUPOVACIO(ELEMENTO *lista){
	return lista = NULL;    //lista siempre sera null al comienzo del programa
}

ELEMENTO * primerElemento(ELEMENTO *lista){
	ELEMENTO *nodoAuxiliar;
	
	if(lista == NULL){
		printf("No hay nodos en la lista");
	}else{
		nodoAuxiliar = lista;
	}
	return lista;
}

ELEMENTO * ULTIMOELEMENTO(ELEMENTO *lista){
	ELEMENTO *nodoAuxiliar, *nodoAnterior;
	if(lista == NULL){
		printf("No hay elementos en la lista!");
	}else{
		nodoAuxiliar = lista;
		while(nodoAuxiliar->siguiente != NULL){
			nodoAnterior = nodoAuxiliar;
			nodoAuxiliar = nodoAnterior->siguiente;
		}
		//nodoAnterior->siguiente=NULL;
	}
	return nodoAuxiliar;
}

ELEMENTO *AGREGAR(int valor, ELEMENTO *lista){
	ELEMENTO *nodoNuevo;
	nodoNuevo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
	if(nodoNuevo != NULL){              // si pudo asignar la cantidad de memoria
		nodoNuevo->dato = valor;    
		nodoNuevo->siguiente = lista;   //hacemos que ELEMENTO apunte a donde lista, ambos son puteros
		lista = nodoNuevo;  //lista apunta al ELEMENTO creado
	}
	return lista;           //devolvemos el ELEMENTO
}
ELEMENTO *insertarNodoFinal(int valor, ELEMENTO *lista){
	ELEMENTO *nodoNuevo, *nodoAuxiliar;
	nodoNuevo = (ELEMENTO*)malloc(sizeof(ELEMENTO));

	if(nodoNuevo != NULL){
		nodoNuevo->dato = valor;
		nodoNuevo->siguiente = NULL;    //le damos null porque queremosque vaya al final.
		if(lista == NULL){              //si no habia nada en la lista
			lista = nodoNuevo;          //el nuevo ELEMENTO que apunta a null, es el unico contenido de la lista.
		}else{
			nodoAuxiliar = lista;       //nodoauxiliar es la lista
			while(nodoAuxiliar->siguiente != NULL)
				nodoAuxiliar = nodoAuxiliar->siguiente;
				nodoAuxiliar->siguiente = nodoNuevo;
		}
	}
	return lista;
}
ELEMENTO *retirarNodoInicio(ELEMENTO *lista){
	ELEMENTO *nodoAuxiliar;
	int dato;
	
	if(lista == NULL){
		printf("No hay nodos en la lista");
	}else{
		nodoAuxiliar = lista;
		dato = nodoAuxiliar->dato;
		lista=nodoAuxiliar->siguiente;
		printf("Se ha retirado el elemento: %d", dato);
		free(nodoAuxiliar);
	}
	return lista;
}
ELEMENTO *QUITARULTIMO(ELEMENTO *lista){
	ELEMENTO *nodoAuxiliar, *nodoAnterior;
	int dato;
	if(lista == NULL){
		//printf("No hay elementos en la lista!");
	}else{
		nodoAuxiliar = lista;
		while(nodoAuxiliar->siguiente != NULL){
			nodoAnterior = nodoAuxiliar;
			nodoAuxiliar = nodoAnterior->siguiente;
		}
		dato = nodoAuxiliar->dato;
		nodoAnterior->siguiente=NULL;
		
		//printf("Se ha retirado el elemento: %d", dato);
		free(nodoAuxiliar);
	}
	return lista;
}
/*
FUNCION union(C,T): GRUPO X GRUPO -> GRUPO
    SI ESVACIO(T)        
        RETORNA C
    SINO
        RETORNA AGREGAR( union( C, QUITARULTIMO(T) ), ULTIMOELEMENTO(T) ) 
*/
ELEMENTO * UNION(ELEMENTO *listaA, ELEMENTO *listaB){
    ELEMENTO *nodoAuxiliar;
    if(listaB == NULL){
		return listaA;
	}else{
        nodoAuxiliar = AGREGAR(nodoAuxiliar->dato,UNION( listaA, QUITARULTIMO(listaB)));
        //return AGREGAR( UNION( listaA, QUITARULTIMO(listaB) ), ULTIMOELEMENTO(listaB) ) ;
        return nodoAuxiliar;
    }
}
void imprimirLista(ELEMENTO *lista){
	ELEMENTO *nodoAuxiliar;
	nodoAuxiliar = lista;
	printf("+++ INICIO +++\n");
	printf("___\n");
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de ELEMENTO aux
		printf("|%d|\n", nodoAuxiliar->dato);
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
	}
	printf("NULL!\n");
}