#include<stdio.h>
#include"cadenas.h"
#include<stdlib.h>

int cad_len(char * string){
    int len =0;

    while (*(string+len))
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
}
char* cad_split(char* string, int separator){
    int count=0;
    char * dest=(char*)calloc(cad_len(string),sizeof(char));    
    while (*(string+count)!=separator){
        dest[count]=*(string+count);
        count++;
    }
    return dest;
}
int main(void){
    char* separado = cad_split("java,python",44);
    printf("%s",separado);
    free(separado);
    return 0;
}