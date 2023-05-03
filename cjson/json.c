#include"listas.h"
#include"json.h"
#include<stdio.h>



char * split(char* string, int separator){
    int i=0;
    int count_bufer=0;
    int count_array=0;
    char *array [BUFSIZ] ;
    char * strbuff [BUFSIZ];
  
        
        while (*(string+i)!=separator)
        {
            strbuff[count_bufer]= *(string+i);
            count_bufer ++;
            i++;

        }
    
    return strbuff;
    
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
        printf("%s",lectura_linea);
        char* separado = split(lectura_linea,58);
        printf("%s",separado);
    }while (fgetc(archivo)!=EOF);
    
    
    fclose(archivo);
}
void JSON_dump(Json_T json,char* fichero,int){printf("tiro todo en un json\n");}

int main(void){

    Json_T parser = Json_parser();
    parser.get(parser,"ejemplo.json");
   

    return 0;
}