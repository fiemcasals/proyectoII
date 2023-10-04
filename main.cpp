#include "claseGato.h"

int main() {

Raton raton1(100,5,3);
Raton raton2(100,5,3);
//Raton raton3(100,5,3);

Gato tom(2,1);

cout<<tom.getEnergia()<<endl;

if(tom.meConvieneCazar(&tom ,&raton1)){
    tom.correr(10.2);
    tom.alimentar(&raton1);
}

cout<<tom.getEnergia()<<endl;

    if(tom.meConvieneCazar(&tom ,&raton2)){
        tom.correr(10.2);
        tom.alimentar(&raton2);
    }

    cout<<tom.getEnergia()<<endl;

    return 0;
}
