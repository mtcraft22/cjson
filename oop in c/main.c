#include<stdio.h>

typedef struct vehiculo
{
    int id;
    int ruedas;
    int arancado;   
    void (*arancar)(struct vehiculo*);
    void (*setruedas)(struct vehiculo*, int ruedas);
    
}Vehiculo_t;
void Arancar(Vehiculo_t*self){
    if (self->arancado){
        self->arancado=0;
    }else{
        printf("Ruuuuummmmmm\n");
        self->arancado=1;
    }
}
void Setruedas(Vehiculo_t*self,int r){
    self->ruedas=r;
}
Vehiculo_t vehiculo_t(int ruedas){
    
    struct vehiculo self;
    
    #define arancar() arancar(self)
    #define setruedas(r) setruedas(self,r)
    self.arancado=0;
    self.ruedas=ruedas;
    self.arancar=Arancar;
    self.setruedas=Setruedas;
    
    return self;
}
int main(void){
    
    Vehiculo_t coche = vehiculo_t(5);
    #define self &coche
    coche.setruedas(5);
    coche.arancar();
    #undef self
    printf("ruedas es: %i\n",coche.ruedas);
    return 0;
}
