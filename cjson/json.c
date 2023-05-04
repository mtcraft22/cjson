#include"listas.h"
#include"json.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char ** split(char* string, int separator){
    int i=0;
    int j=0;
    int count_bufer=0;
    int count_array=0;
    char** array=(char **)calloc(BUFSIZ,sizeof(char));
    char* strbuff=(char *)calloc(BUFSIZ,sizeof(char));
        while (*(string+j))
        {
        
            i=j;
            count_bufer=0;

            while (*(string+i)!=separator)          
            {
                strbuff[count_bufer]= *(string+i);
                count_bufer ++;
                i++;
            }
            array[count_array]= strbuff;
            count_array++;
            j+=i;
        
        }
    return array;
    
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
        char** separado = split(lectura_linea,58);
        printf("Extrato: %s\n",separado[0]);
        printf("Extrato2: %s\n",separado[1]);
        free(separado);
    }while (fgetc(archivo)!=EOF);
    
    
    fclose(archivo);
}
void JSON_dump(Json_T json,char* fichero,int){printf("tiro todo en un json\n");}

int main(void){

    Json_T parser = Json_parser();
    parser.get(parser,"ejemplo.json");
   

    return 0;
}