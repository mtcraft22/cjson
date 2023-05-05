#include"listas.h"
#include"json.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char** split(char* string, int separator){

    int count=0;
    int A_count=0;
    char * firts;
    char **final;
    while (*(string+count)!=10)
    {
        while (*(string+count)!=separator){
            firts[count]=string[count];
            count++;
        }   
        firts[count]=0;
        final[A_count]=firts;
        A_count ++;
    }
    return final;
}    


Json_T Json_parser(){
    Json_T json;
    Lista obj;
    json.dump=JSON_dump;
    json.get=JSON_get_all;
    json.to_str=JSON_2_STRING;
    json.obj=obj;
    return json;
}

char *JSON_2_STRING(Json_T json){printf("transformo en string\n");return "c el mejor";}
void JSON_get_all(Json_T json,char* fichero){
    
    FILE* archivo=fopen(fichero,"r");
    char lectura_linea[BUFSIZ];
    do{
        fgets(lectura_linea,BUFSIZ,archivo);
        char** separado = split(lectura_linea,58);
        printf("Extrato: %s\n",separado[0]);
        
    }while (fgetc(archivo)!=EOF);
    
    
    fclose(archivo);
}
void JSON_dump(Json_T json,char* fichero,int){printf("tiro todo en un json\n");}

int main(void){

    Json_T parser = Json_parser();
    parser.get(parser,"ejemplo.json");
   

    return 0;
}