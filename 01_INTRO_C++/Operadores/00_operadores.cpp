#include <iostream>
#include <math.h>

using namespace std;

class Complejo {

public:
    float real;
    float imga;

    void mostrar() {
        cout << "( " << real << " + " << imga << "i )" << endl;
    }

    float modulo() {
        return powf(real, 2) + powf(imga, 2);
    }

    Complejo sumar(Complejo b) {
        Complejo suma;
        suma.real = real + b.real;
        suma.imga = imga + b.imga;
        return suma;
    }

    Complejo operator+(int b) {
        Complejo suma;
        suma.real = real + b;
        suma.imga = imga;
        return suma;
    }

    Complejo operator+(Complejo b) {
        return sumar(b);
    }

    bool operator>(Complejo b) {
        return modulo() > b.modulo();
    }
};

Complejo operator+(int a, Complejo b) {
    return b + a;
}

int main(int argc, char const *argv[]) {

    Complejo i, j;
    Complejo resultado;

    i.real = 8;
    i.imga = 9;

    j.real = -2;
    j.imga = 0;

    resultado = i + j;

    i.mostrar();
    i = i + 1;
    i.mostrar();
    i = 1 + i;
    i.mostrar();

    (i + j).mostrar();

    resultado.mostrar();

    if (i > j)
        cout << " i es mayor que j " << endl;
}