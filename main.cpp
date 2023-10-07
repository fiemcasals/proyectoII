#include <iostream>
#include <cmath>
#include <list>
#include "validaciones.h"
#define F 5
#define C 5
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
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
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
    float tiempo;
    int cantidad;

public:
    Gato(int x, int y,float t, int c): energia(100), velocidad(5), posX(x), posY(y), tiempo(t), cantidad(c){}

    void alimentar(Raton *ratonComido){
        energia+=(ratonComido->getPeso()+12);
        cantidad++;
    }
    void correr(float time){
        velocidad=(energia/10)+5;
        energia=energia-(time*velocidad)*0.5;
        tiempo=tiempo+time;
    }

    void estadoActual() const{
        cout<<"La energia del gato es de: "<<energia<<" jouls"<<endl;
        cout<<"Comio: "<<cantidad<<" de ratones"<<endl;
        cout<<"Corrio por: "<<tiempo<<"s"<<endl;
    }
    bool meConvieneCazar(int distancia, double peso) const {
        float tiempo= (float ) distancia/velocidad;
        if ((tiempo*velocidad*0.5)<peso+12) {
            return true;
        } else {
            cout << "No le conviene cazar el ratón" << endl;
            return false;
        }
    }
    int distancia(float time){
        int distancia;
        distancia=(int) velocidad* time;
        return distancia;
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
    list<Raton> ratones;
public:
    void agregarRaton(Raton & newRaton){
        ratones.push_back(newRaton);
    }
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
    void gestion(){
        Mapa mapa;
        Raton raton1(78.0,3,2,1);
        Raton raton2(100,4,4,2);
        agregarRaton(raton1);
        agregarRaton(raton2);
        Gato tom(0,0,0,0);
        mapa.crearMapa();
        insertarRaton(mapa,raton1);
        insertarRaton(mapa,raton2);
        insertarGato(mapa,tom);
        while (true){
            mapa.mostrar();
            int respuesta;
            cout<<"Que hace TOM:\n 1-Corre\n2-Se come un raton\n3-Ver estado actual\n4-Me canse de ver a TOM:"<<endl;
            respuesta= obtenerRespuestaValida();
            if (respuesta==1){
                if (tom.getEnergia()==0){
                    cout<<"tom se quedo sin energia"<<endl;
                }else{
                    int newposx, newposy;
                    float time;
                    cout<<"Ingrese a donde se desplazo Tom en x:"<<endl;
                    newposx=obtenerPosicionValida();
                    cout<<"Ingrese a donde se desplazo Tom en y:"<<endl;
                    newposy=obtenerPosicionValida();
                    if (mapa.chequearPosicion(newposx,newposy)){
                        cout<<"Ingrese el tiempo que tardo tom en moverse en s:"<<endl;
                        time=obtenerTiempValido();
                        int ax,ay;
                        ax=tom.getposX();
                        ay=tom.getposY();
                        tom.correr(time);
                        tom.setPosicion(newposx,newposy);
                        insertarGato(mapa,tom);
                        mapa.eliminarObjeto(ax,ay);
                    }else{
                        cout<<"El gato no tenia ganas de correr"<<endl;
                    }
                }
            }else if (respuesta==2){
                int rat;
                float time;
                cout<<"Que raton se come tom??";
                rat=obtenerRatonValido();
                if (rat==1){
                    cout<<"Ingrese el tiempo que tardo tom en moverse en s:"<<endl;
                    time=obtenerTiempValido();
                    int distancia=tom.distancia(time);
                    if(tom.meConvieneCazar(distancia,raton1.getPeso()))
                    {
                        int newposx,newposy,ax,ay;
                        ax=tom.getposX();
                        ay=tom.getposY();
                        newposx=raton1.getposX();
                        newposy=raton1.getposY();
                        tom.correr(time);
                        tom.alimentar(&raton1);
                        tom.setPosicion(newposx,newposy);
                        insertarGato(mapa,tom);
                        mapa.eliminarObjeto(ax,ay);
                    }
                }else{
                    cout<<"Ingrese el tiempo que tardo tom en moverse en s:"<<endl;
                    time=obtenerTiempValido();
                    int distancia=tom.distancia(time);
                    if(tom.meConvieneCazar(distancia,raton2.getPeso()))
                    {
                        int newposx,newposy,ax,ay;
                        ax=tom.getposX();
                        ay=tom.getposY();
                        newposx=raton2.getposX();
                        newposy=raton2.getposY();
                        tom.correr(time);
                        tom.alimentar(&raton2);
                        tom.setPosicion(newposx,newposy);
                        insertarGato(mapa,tom);
                        mapa.eliminarObjeto(ax,ay);
                    }
                }
            } else if(respuesta==3){
                tom.estadoActual();
            }else{
                break;
            }
            cout<<""<<endl;
            system("PAUSE");

        }
    }
};

int main(){

    Menu menu;
    menu.gestion();
    return 0;
}
