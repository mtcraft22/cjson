#include"listas.h"
#include"json.h"
#include<stdio.h>



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
void JSON_get_all(Json_T json,FILE* fichero){printf("cojo todo de un json\n");}
void JSON_dump(Json_T json,FILE* fichero,int){printf("tiro todo en un json\n");}

int main(void){
    FILE* json_entidades= fopen("ejemplo.json","r");
    Json_T parser = Json_parser();
    parser.dump(parser,json_entidades,APPEND);
    parser.get(parser,json_entidades);
    parser.to_str(parser);
    fclose(json_entidades);
    return 0;
}