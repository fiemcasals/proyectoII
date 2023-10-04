
class Raton{
private:
    float peso;
    int posX;
    int posY;
public:

    Raton(float peso, int x, int y): peso(peso), posX(x), posY(y){}

    float getpeso(){
        return peso;
    }

    int getposX(){return posX;}
    int getposY(){return posY;}

    //falta hacer el destructor
};