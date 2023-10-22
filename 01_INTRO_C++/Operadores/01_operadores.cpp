#include <iostream>
#include <math.h>

using namespace std;

class Complejo {

public:
    float real;
    float imag;

    Complejo(float r, float i) : real(r), imag(i) {
        real = r;
        imag = i;
    }

    void mostrar() {
        cout << "( " << real << " + " << imag << "i )" << endl;
    }

    float modulo() {
        return powf(real, 2) + powf(imag, 2);
    }

    Complejo sumar(Complejo b) {
        Complejo suma((real + b.real), (imag + b.imag));
        return suma;
    }

    Complejo operator+(int b) {
        Complejo suma((real + b), (imag));
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

    Complejo i(8, 9), j(-2, 0);
    Complejo resultado(i + j);

    //  resultado = sumar(i, j);

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
