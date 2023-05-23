#include"dicionarios.h"
#include<stdio.h>

int main (void){

    Lista SO_lin;

    Pares win;
    win.clave="Windows";
    win.valor="Nueva tecnologia";
    Pares gnu_linux;
    gnu_linux.clave="Gnu_con_linux";
    gnu_linux.valor="Minix";
    Insertar_pricipio(&SO_lin,&win);
    Insertar_final(&SO_lin,&gnu_linux);
    void printar(Pares* par){
        printf("Clave: %s, Valor: %s\n", par->clave, par->valor);
    }

    por_cada(&SO_lin,printar);

    void* valor2=clave(&SO_lin,"Minix");
    if (valor2!=NULL){
        printf("%s",valor2);
    }else{
        printf("no encontrado el valor");
    }
    return 0;

}