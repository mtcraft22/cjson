#include"listas.h"
#include"cadenas.h"
#include"json.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Json_T Json_parser(){
    Json_T json;
    Lista obj;
    json.dump=JSON_dump;
    json.get=JSON_get_all;
    json.to_str=JSON_2_STRING;
    json.obj=obj;
    return json;
}
void Desctructor_Json_parser(Json_T *instace){
    Nodo* actual=instace->obj.cabeza;
	while (actual->siguiente)
	{
		destruir_nodo(actual);
		actual=actual->siguiente;
	}
    destruir_nodo(actual);
}
char *JSON_2_STRING(Json_T json){printf("transformo en string\n");return "c el mejor";}
Lista JSON_get_all(Json_T json,char* fichero){
    FILE* archivo=fopen(fichero,"r");
    char lectura_linea[BUFSIZ];
    Pares mounstro;
    Lista mounstros;
    do{
        fgets(lectura_linea,BUFSIZ,archivo);
        char* clave = cad_split(lectura_linea,58);
        char* valor = cad_slice(lectura_linea,cad_len(clave)+1,cad_len(lectura_linea));
        mounstro.clave=clave;
        mounstro.valor=valor;
        Insertar_pricipio(&mounstros,&mounstro);
        

    }while (fgetc(archivo)!=EOF);
     
    
    fclose(archivo);
    return mounstros;
}
void JSON_dump(Json_T json,char* fichero,int){printf("tiro todo en un json\n");}


//definimos la structura para volcar informacion json leia de un fichero se guardara en el mcampo obj de 
//la structura json en forma de lista dinamica


int main(void){
    
    Json_T parser = Json_parser();
    Lista js =parser.get(parser,"ejemplo.json");

    Pares * p= obtener(&js,9);
    printf("%s\n",p->clave);
    printf("%s\n",p->valor);
    Desctructor_Json_parser(&parser);
    return 0;
}