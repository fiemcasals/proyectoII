//
// Created by furfa on 7/10/2023.
//

#include "validaciones.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int obtenerRespuestaValida() {
    int numero;
    string entrada;
    while (true) {
        cout << "Respuesta(1/2/3/4): ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero==1 || numero==2 || numero==3 || numero==4) {
                    break;
                } else {
                    cout << "El numero debe ser 1,2 o 3. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}

int obtenerPosicionValida() {
    int numero;
    string entrada;
    while (true) {
        cout << "Respuesta(0/1/2/3/4): ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero>=0 && numero<=4) {
                    break;
                } else {
                    cout << "El numero debe estar entre 0 y 4. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}

float obtenerTiempValido() {
    float numero;
    string entrada;
    while (true) {
        cout << "Respuesta: ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero>0) {
                    break;
                } else {
                    cout << "El numero debe ser postivo. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}

int obtenerRatonValido() {
    int numero;
    string entrada;
    while (true) {
        cout << "Respuesta(1-2): ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero==1 || numero==2 ) {
                    break;
                } else {
                    cout << "El numero debe ser 1,2 o 3. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}

