#include <stdio.h>
#include <string.h>
typedef struct {
    char* nombre;
    int edad;
    struct Persona *next;
}Persona;
Persona* dictlist[10];

int j = 0;

unsigned int hash(char* nombre){
    unsigned int value = 0;
    int len = strnlen(nombre,256);
    int i = 0;
    for (i;i<len;i++){
        value +=nombre[i];
        value = (value*nombre[i]) %10;
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
Persona * get_pair (Persona* persona){
    if(dictlist[hash(persona->nombre)]==persona){
        return dictlist[hash(persona->nombre)];
    } else{
        return NULL;
    }
}
int main(void ){
    Persona pepe = {.nombre="pepe",.edad=23};
    Persona marc = {.nombre="marc",.edad=33};
    Persona jose = {.nombre="jose",.edad=43};
    Persona luis = {.nombre="luis",.edad=53};
    Persona juan = {.nombre="juan",.edad=63};
    Persona paco = {.nombre="paco",.edad=73};
    Persona maria = {.nombre="maria",.edad=18};
    Persona pepe2 = {.nombre="pepeluis",.edad=23};
    Persona marc2 = {.nombre="marcjuajo",.edad=33};
    Persona jose2 = {.nombre="joseluis",.edad=43};
    Persona luis2 = {.nombre="luisfuf",.edad=53};
    Persona juan2 = {.nombre="juanfof",.edad=63};
    Persona paco2 = {.nombre="pacof",.edad=73};
    Persona maria2 = {.nombre="mariases",.edad=18};

    insertar(&paco);
    insertar(&pepe);
    insertar(&marc);
    insertar(&jose);
    insertar(&luis);
    insertar(&juan);
    insertar(&maria);
    insertar(&paco2);
    insertar(&pepe2);
    insertar(&marc2);
    insertar(&jose2);
    insertar(&luis2);
    insertar(&juan2);
    insertar(&maria2);
    debug_map(dictlist, 10);
}