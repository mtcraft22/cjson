#pragma once
#include"listas.h"
#define APPEND 0
#define REPLACE 1

typedef struct json
{
    Lista obj;
    void(*get)(struct json,char *);
    void(*dump)(struct json,char *,int);
    char*(*to_str)(struct json);
}Json_T;

void JSON_get_all(Json_T json,char * fichero);
void JSON_dump(Json_T json,char * fichero,int mode);
char* JSON_2_STRING(Json_T json);
Json_T Json_parser();
