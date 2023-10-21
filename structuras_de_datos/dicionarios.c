#include <stdio.h>
#include <string.h>

int hash_size = 20;

typedef struct {
    char* nombre;
    int edad;
    struct Persona *next;
}Persona;

Persona* dictlist[BUFSIZ];
unsigned int hash(char* nombre){
    unsigned int value = 0;
    int len = strnlen(nombre,256);
    int i = 0;
    for (i;i<len;i++){
        value +=nombre[i];
        value = (value*nombre[i]) %hash_size;
    }
    return value ;
}

void insertar(Persona* persona){
    
    if(dictlist[hash(persona->nombre)]==NULL){
        dictlist[hash(persona->nombre)]=persona;
    }else{
        Persona *sig= (Persona *) dictlist[hash(persona->nombre)]->next;
        if (sig==NULL){
            dictlist[hash(persona->nombre)]->next=persona;
        }else {
            while (sig->next) {
                sig= (Persona *) sig->next;
            }
            sig->next=persona;
        }
    }
}
void debug_map(Persona*map_array[],int array_map_size){
    int i = 0;
    for (i;i<array_map_size;i++){
        if (map_array[i]){
            Persona *coso = map_array[i];
            printf("%d ----: %s<-->%d",hash(coso->nombre),coso->nombre,coso->edad);
            coso= (Persona *) coso->next;
            while (coso!=NULL) {
                printf("----> %s<-->%d",coso->nombre,coso->edad);
                coso= (Persona *) coso->next;
            }
        }else {
            printf("%d------------",i);
        }
        putc(10, stdout);
    }
}
Persona * get_pair (char * clave){

    if(strcmp(dictlist[hash(clave)]->nombre, clave)==0){

        return dictlist[hash(clave)];
    } else{
        Persona * coso = dictlist[hash(clave)];
        while (coso!=NULL){
            if (strcmp(coso->nombre, clave)==0){
                return coso;
            }
            coso=(Persona *)coso->next;
        }
        return NULL;
    }
}
int main(void ){
    Persona a = {.nombre="pepe",.edad=23};
    Persona b = {.nombre="marc",.edad=33};
    Persona c = {.nombre="jose",.edad=93};
    Persona d = {.nombre="luis",.edad=53};
    Persona e = {.nombre="pepociojose",.edad=76};
    
    insertar(&a); 
    insertar(&b); 
    insertar(&c); 
    insertar(&d);
    insertar(&e);
    if( get_pair("pepociojose")){
        printf("%d\n", get_pair("pepociojose")->edad);
    }

    debug_map(dictlist, hash_size);
}