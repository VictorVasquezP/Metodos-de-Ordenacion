#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodo{
	int dato;
	struct nodo* sig;
}nodo;
nodo* inicio=NULL;
nodo* fin=NULL;
void insertar();
void ver();
void shell();
int main(int argc, char *argv[]) {
	int opc;
	while(opc!=5){
		printf("\n\t1.-Insertar\n\t2.- Ver\n\t3.-Shell\n\t5.- Salir\n");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
		case 1:
			insertar();
			break;
		case 2:
			ver();
			break;
		case 3:
			shell();
			shell();
			break;
		}
	}
	return 0;
}
void insertar(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf("\nIngrese el nuevo dato: ");
	scanf("%d",&nuevo->dato);
	if(inicio == NULL){
		inicio= nuevo;
		nuevo->sig=NULL;
		fin=nuevo;
	}else{
		fin->sig=nuevo;
		nuevo->sig=NULL;
		fin=nuevo;
	}
}
void ver(){
	nodo* aux=(nodo*)malloc(sizeof(nodo));
	aux=inicio;
	if(aux!=NULL){
		printf("\n---------------------------\n");
		while(aux!=NULL){
			printf("%d",aux->dato);
			printf(" -> ");
			aux=aux->sig;
		}
		printf("NULL\n");
	}else{
		printf("\nLista vacia\n");
	}
}
void shell(){
	int cont=0;
	nodo* aux2=(nodo*)malloc(sizeof(nodo));
	aux2=inicio;
	if(aux2!=NULL){
		while(aux2!=NULL){
			aux2=aux2->sig;
			cont++;
		}
		//
		nodo* q=(nodo*)malloc(sizeof(nodo));
		nodo* p=(nodo*)malloc(sizeof(nodo));
		nodo* aux=(nodo*)malloc(sizeof(nodo));
		int k = cont / 2;
		while (k > 0) {
			q = inicio;
			//falta colocar el final
			for (int i = 0; i < k; i++) {
				q = q->sig;
			}
			p = inicio;
			while (q != NULL) {
				if (p->dato > q->dato) {
					aux->dato= p->dato;
					p->dato = q->dato;
					q->dato = aux->dato;
				}
				p = p->sig;
				q = q->sig;
			}
			k = k / 2;
		}
	}else{
		printf("\nLista vacia\n");
	}
}
