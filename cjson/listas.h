#ifndef list
#define list 

typedef struct vector
{
	char *clave;
	char *valor;
}Vector;

typedef struct nodo
{
	Vector v;
	struct nodo* siguiente;	
}Nodo;

typedef struct li
{
	Nodo* cabeza;
    int Longitud;
	
}Lista;

Nodo* crear_nodo(Vector* dato);
void destruir_nodo(Nodo* nodo);
void Insertar_pricipio(Lista* lista, Vector* dato);
void Insertar_final(Lista* lista, Vector* dato);
void Insertar_Despues(int n, Lista* lista, Vector* dato);
Vector* obtener(Lista* Lista, int n);
int Longitud(Lista* lista);
void Elimina_final(Lista* lista);
void Elimina_enmedio(Lista* lista, int n);
void por_cada(Lista* lista , void(*funcion)(Vector* dato));
#endif //final list

