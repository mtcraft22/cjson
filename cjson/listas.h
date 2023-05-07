#ifndef list
#define list 

typedef struct pares
{
	void* clave;
	void* valor;
}Pares;

typedef struct nodo
{
	Pares v;
	struct nodo* siguiente;	
}Nodo;

typedef struct li
{
	Nodo* cabeza;
    int Longitud;
	
}Lista;

Nodo* crear_nodo(Pares* dato);
void destruir_nodo(Nodo* nodo);
void Insertar_pricipio(Lista* lista, Pares* dato);
void Insertar_final(Lista* lista, Pares* dato);
void Insertar_Despues(int n, Lista* lista, Pares* dato);
Pares* obtener(Lista* Lista, int n);
int Longitud(Lista* lista);
void Elimina_final(Lista* lista);
void Elimina_enmedio(Lista* lista, int n);
void por_cada(Lista* lista , void(*funcion)(Pares* dato));
#endif //final list

