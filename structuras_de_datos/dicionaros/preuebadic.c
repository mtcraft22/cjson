#include"dicionarios.h"
#include<stdio.h>
#include<stdlib.h>

int main (void){
    Lista SO_lin;

    Pares win;
    win.clave="Windows";
    win.valor="Nueva tecnologia";
    Pares gnu_linux;
    gnu_linux.clave="Gnu_con_linux";
    gnu_linux.valor="minix";
    Pares macOS;
    macOS.clave="macOS";
    macOS.valor="darwin";
    Insertar_pricipio(&SO_lin,&win);
    Insertar_final(&SO_lin,&gnu_linux);
    Insertar_pricipio(&SO_lin,&macOS);
    void printar(Pares* par){
        printf("Clave: %s, Valor: %s\n", par->clave, par->valor);
    }

    por_cada(&SO_lin,printar);

    void* valor2=clave(&SO_lin,"darwin");
    if (valor2!=NULL){
        printf("%s",valor2);
    }else{
        printf("no encontrado el valor");
    }


    win.clave="java";
    por_cada(&SO_lin,printar);
    void destruir_lista(Lista *lista){
        Nodo* actual=lista->cabeza;
        while (actual->siguiente)
        {
            free(actual);
            actual=actual->siguiente;
        }
        free(actual);    
    }
    destruir_lista(&SO_lin);

    return 0;
    
    

}