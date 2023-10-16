#include <stdio.h>

typedef struct pair {
    void * key;
    void * value;
}Pair;

int main (void){

    float value = 23.6;
    char *key = "java";
    Pair pair  = {.key=key,.value=&value};
    printf("%s %.2f",(char*)pair.key,*(float *)pair.value);
    
    return 0;

}