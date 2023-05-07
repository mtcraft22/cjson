#include<stdio.h>
#include<stdlib.h>
#include"listas.h"

Nodo* crear_nodo(Pares* dato){
	Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->v.clave=dato->clave;
	nodo->v.valor=dato->valor;
	nodo->siguiente=NULL;
	return nodo;
}

void destruir_nodo(Nodo* nodo){
	free(nodo);
}

void Insertar_pricipio(Lista* lista, Pares* dato){
	Nodo* nodo=crear_nodo(dato);
	nodo->siguiente=lista->cabeza;
	lista->cabeza=nodo;
	lista->Longitud++;
}
void Insertar_final(Lista* lista, Pares* dato){
	Nodo* nodo=crear_nodo(dato);
	if (lista->cabeza==NULL){
		lista->cabeza= nodo;
	}else{
		Nodo* actual=lista->cabeza;
		while (actual->siguiente)
		{
			actual=actual->siguiente;
		}
		actual->siguiente=nodo;
	}
	lista->Longitud++;
}
void Insertar_Despues(int n, Lista* lista, Pares* dato){
	Nodo* nodo=crear_nodo(dato);
	if (lista->cabeza==NULL){
		lista->cabeza= nodo;
	}else{
		int contador=0;
		Nodo* actual=lista->cabeza;
		while (actual->siguiente && contador<n )
		{
			actual=actual->siguiente;
			contador++;
		}
		nodo->siguiente=actual->siguiente;
		actual->siguiente=nodo;
	}
	lista->Longitud++;

}
Pares* obtener(Lista* lista, int n){
	if (lista->cabeza==NULL){
		return NULL;
	}else{
		int contador=0;
		Nodo* actual=lista->cabeza;
		while (actual->siguiente && contador<n )
		{
			actual=actual->siguiente;
			contador++;
		}
		if (contador!=n){
			return NULL;
		}else{
			return &actual->v;
		}
	}
}

int Longitud(Lista* lista){return lista->Longitud;}
void Elimina_pricipio(Lista* lista){
	if (lista->cabeza){
		Nodo* eliminar = lista->cabeza;
		lista->cabeza=eliminar->siguiente;
		destruir_nodo(eliminar);
		lista->Longitud--;
	}
	
}
void Elimina_final(Lista* lista){
	if (lista->cabeza){
		if (lista->cabeza->siguiente){
			Nodo* actual=lista->cabeza;
			while (actual->siguiente->siguiente)
			{
				actual=actual->siguiente;
			}
			Nodo* eliminado = actual->siguiente;
			actual->siguiente=NULL;
			destruir_nodo(eliminado);
		}else{
			Nodo* eliminado= lista->cabeza;
			lista->cabeza=NULL;
			destruir_nodo(eliminado);
		}
	}
	lista->Longitud--;
}

void Elimina_enmedio(Lista* lista, int n){
	if(lista->cabeza){
		if (n==0){
			Elimina_pricipio(lista);
		}else if (n<Longitud(lista)){
			Nodo* actual=lista->cabeza;
			int contador=0;
			while (actual->siguiente && (n-1))
			{
				actual=actual->siguiente;
				contador++;
			}
			Nodo* eliminado = actual->siguiente;
			actual->siguiente=eliminado->siguiente;
			destruir_nodo(eliminado);
		}
	}
	lista->Longitud--;
}
void por_cada(Lista* lista , void(*funcion)(Pares* dato)){
	Nodo* actual=lista->cabeza;
	while (actual->siguiente)
	{
		funcion(&actual->v);
		actual=actual->siguiente;
	}
	funcion(&actual->v);
}