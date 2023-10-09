#include <iostream>
#include <cmath>
#include <string>
#include "validaciones.h"
#define F 10
#define C 10
using namespace std;
class Mapa{
private:
    char m[F][C];
public:
    void crearMapa(){
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                m[i][j]=' ';
            }
        }
    }
    void setCat(int posx,int posy){
        m[posx][posy]='O';
    }
    void eliminarObjeto(int posx,int posy){
        m[posx][posy]=' ';
    }
    void setRaton(int posx,int posy){
        m[posx][posy]='X';
    }
    bool chequearPosicion(int posx, int posy){
        if(m[posx][posy]==' '){
            return true;
        } else
            return false;
    }
    void mostrar(){
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                printf("%c|",m[i][j]);
            }
            printf("\n");
        }
    }
};
class Raton {
private:
    double peso;
    int posx;
    int posy;
    int numero;
public:
    Raton(double aux,int x, int y,int n){
        peso=aux;
        posx=x;
        posy=y;
        numero=n;
    }
    double getPeso() const{
        return peso;
    }
    int getposX () const{
        return posx;
    }
    int getposY() const{
        return posy;
    }
    ~Raton() = default;

};


class Gato{

private:
    double energia;
    double velocidad;
    int posX;
    int posY;
    double tiempo;
    int cantidad;

public:
    Gato(int x, int y,float t, int c): energia(10), velocidad(5), posX(x), posY(y), tiempo(t), cantidad(c){}

    void alimentar(Raton *ratonComido){
        energia+=(ratonComido->getPeso()+12);
        cantidad++;
    }
    void correr(int x, int y){
        velocidad=(energia/10)+5;
        double modulo= distancia(x,y);
        energia=energia-modulo*0.5;
        tiempo=tiempo+(modulo/velocidad);
    }

    void estadoActual() const{
        cout<<"La energia del gato es de: "<<energia<<" jouls"<<endl;
        cout<<"Comio: "<<cantidad<<" de ratones"<<endl;
        cout<<"Corrio por: "<<tiempo<<"s"<<endl;
    }
    bool meConvieneCazar(double distancia, double peso) const {
        double tiempo= (double) distancia/velocidad;
        if ((tiempo*velocidad*0.5)<peso+12) {
            return true;
        } else {
            cout << "No le conviene cazar el ratón" << endl;
            return false;
        }
    }
    double distancia(int x, int y) const{
        int distx,disty;
        if (posX>x)
            distx=posX-x;
        else
            distx=x-posX;
        if (posY>y)
            disty=posY-y;
        else
            disty=y-posY;
        double modulo;
        modulo=(double ) sqrt((distx*distx)+(disty*disty));
        return modulo;
    }
    void setPosicion(int x, int y){
        posX=x;
        posY=y;
    }

    double getEnergia() const{
        return energia;
    }
    int getposX () const{
        return posX;
    }
    int getposY() const{
        return posY;
    }

};
class Menu{
private:

public:
    static void insertarRaton(Mapa &maps,Raton &aux){
        int x,y;
        x=aux.getposX();
        y=aux.getposY();
        maps.setRaton(x,y);
    }
    static void insertarGato(Mapa &maps,Gato &aux){
        int x,y;
        x=aux.getposX();
        y=aux.getposY();
        maps.setCat(x,y);
    }
    void realizarMvimiento(Mapa & mapa,Gato &tom,Raton &aux){
        int newposx,newposy,ax,ay;
        ax=tom.getposX();
        ay=tom.getposY();
        newposy=aux.getposY();
        newposx=aux.getposX();
        double modulo=tom.distancia(newposx,newposy);
        if(tom.meConvieneCazar(modulo,aux.getPeso()))
        {
            tom.correr(newposx,newposy);
            tom.alimentar(&aux);
            tom.setPosicion(newposx,newposy);
            insertarGato(mapa,tom);
            mapa.eliminarObjeto(ax,ay);
        }
    }
    void gestion(){
        Mapa mapa;
        Raton raton1(20.0,0,0,1);
        Raton raton2(10.0,1,7,2);
        Raton raton3(4.0,3,3,3);
        Raton raton4(15.0,6,2,4);
        Raton raton5(11.0,7,8,5);
        Raton raton6(8.0,8,3,6);
        Raton raton7(12.0,9,9,7);
        Gato tom(5,5,0,0);
        mapa.crearMapa();
        insertarRaton(mapa,raton1);
        insertarRaton(mapa,raton2);
        insertarRaton(mapa,raton3);
        insertarRaton(mapa,raton4);
        insertarRaton(mapa,raton5);
        insertarRaton(mapa,raton6);
        insertarRaton(mapa,raton7);
        insertarGato(mapa,tom);
        int ratonprevio=0;
        while (true){
            mapa.mostrar();
            int respuesta;
            cout<<"Que hace TOM:\n 1-Corre\n2-Se come un raton\n3-Ver estado actual\n4-Me canse de ver a TOM:"<<endl;
            respuesta= obtenerRespuestaValida();
            if (tom.getEnergia()<0){
                cout<<"tom se quedo sin energia"<<endl;
                break;
            }
            else{
                if (respuesta==1){
                    {
                        int newposx, newposy;
                        cout<<"Ingrese a donde se desplazo Tom en x:"<<endl;
                        newposx=obtenerPosicionValida();
                        cout<<"Ingrese a donde se desplazo Tom en y:"<<endl;
                        newposy=obtenerPosicionValida();
                        if (mapa.chequearPosicion(newposx,newposy)){
                            int ax,ay;
                            ax=tom.getposX();
                            ay=tom.getposY();
                            tom.correr(newposx,newposy);
                            tom.setPosicion(newposx,newposy);
                            insertarGato(mapa,tom);
                            mapa.eliminarObjeto(ax,ay);
                        }else{
                            cout<<"El gato no puede ir a esa posicion"<<endl;
                        }
                    }
                }else if (respuesta==2){
                    int rat;
                    cout<<"Que raton se come tom??";
                    rat=obtenerRatonValido();
                    if(rat==ratonprevio)
                    {
                        cout<<"Tom ya se comio ese raton"<<endl;
                        ratonprevio=rat;
                    }else{
                        if (rat==1){
                            realizarMvimiento(mapa,tom,raton1);
                        }else if (rat==2){
                            realizarMvimiento(mapa,tom,raton2);
                        }else if (rat==3){
                            realizarMvimiento(mapa,tom,raton3);
                        }else if (rat==4){
                            realizarMvimiento(mapa,tom,raton4);
                        }else if (rat==5){
                            realizarMvimiento(mapa,tom,raton5);
                        }else if (rat==6){
                            realizarMvimiento(mapa,tom,raton6);
                        }else {
                            realizarMvimiento(mapa,tom,raton7);
                        }
                        ratonprevio=rat;
                    }
                } else if(respuesta==3){
                    tom.estadoActual();
                }else{
                    break;
                }
            }
            cout<<""<<endl;
            system("PAUSE");
        }
        tom.estadoActual();
    }
};

int main(){
    Menu menu;
    menu.gestion();
    return 0;
}