#include<stdio.h>
typedef struct object
{
    void* self;
    void* super;

}Object_t;

typedef struct vehiculo
{
    int ruedas;
    int arancado;
    void (*arancar)(struct vehiculo*);
    
}Vehiculo_t;
typedef struct camion
{
    Vehiculo_t *super;
    char* tipo_carga;
    int carga;
    void (*descargar)(struct camion*);


}Camion_t;
void arancar(Vehiculo_t*self){
    if (self->arancado){
        self->arancado=0;
    }else{
        printf("Ruuuuummmmmm\n");
        self->arancado=1;
    }
}

Vehiculo_t vehiculo_t(int ruedas){
    Vehiculo_t self;
    self.arancado=0;
    self.ruedas=ruedas;
    self.arancar=arancar;
    return self;
}
int main(void){
    Vehiculo_t coche=vehiculo_t(4);
    coche.arancar(&coche);
    return 0;
}