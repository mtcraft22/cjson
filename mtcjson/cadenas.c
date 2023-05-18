#include<stdio.h>
#include"cadenas.h"
#include<stdlib.h>
#include<memory.h>



int cad_len(char * string){
    int len =0;

    while (*(string+len)!=0)
    {
        len++;
    }
    return len;
    
}


char* cad_slice(char* string, int init,int final){
    char *stringf=(char *)calloc(cad_len(string),sizeof(char));
    int index=0;
    for (init; final>init;init++){
        stringf[index]=string[init];
        index++;
    }
    return stringf;
}


char* cad_split(char* string, int separator){
    int count=0;
    char * dest=(char*)calloc(cad_len(string),sizeof(char));    
    while (*(string+count)!=separator ){
        dest[count]=*(string+count);
        count++;
        if(cad_len(string)<count){
            break;
        }
    }
    return dest;
}
