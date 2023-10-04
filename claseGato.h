#include <iostream>
#include <cmath>
#include "raton.h"

using namespace std;

class Gato{

private:
    double energia;
    double velocidad;
    int posX;
    int posY;

public:
    Gato(int x, int y): energia(100), velocidad(5), posX(x), posY(y){}

    void alimentar(Raton *ratonComido){
        energia+=(ratonComido->getpeso()+12);
    }
    void correr(float tiempo){
        velocidad=(energia/10)+5;
        energia-=(tiempo*velocidad)*0.5;
    }
    float getDistancia(Raton *ratonACazar){
        return sqrt((posX-ratonACazar->getposX())*(posY-ratonACazar->getposY())+(posX-ratonACazar->getposX())*(posY-ratonACazar->getposY()));
    }

    bool meConvieneCazar(Gato *tom, Raton *ratonACazar) {
        if (ratonACazar->getpeso() + 12 > tom->getDistancia(ratonACazar) * 0.5) {
            tom->correr(10.2); // No necesitas pasar *ratonACazar aquí.
            tom->alimentar(ratonACazar); // No necesitas pasar *ratonACazar aquí.
        } else {
            cout << "No le conviene cazar el ratón" << endl;
        }
    }

    double getEnergia(){return energia;};

};

