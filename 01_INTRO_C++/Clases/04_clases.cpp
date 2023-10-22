#include <iostream>

using namespace std;

class Cuenta {

public:
    string numCuenta;
    string titular;
    float saldo;

    void ingresar(float cantidad) {
        if (cantidad >= 0)
            saldo += cantidad;
    }

    bool retirar(float cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            return true;
        }
        return false;
    }

    Cuenta() {}
};

void mostrar(Cuenta c) {

    cout << "La cuenta de " << c.titular << " tiene " << c.saldo << " euros " << endl;
};

void procesarIngreso(Cuenta *pc) {

    float cantidad;

    cout << "Introduce la cantidad a ingresar ";
    cin >> cantidad;
    Cuenta c1 = *pc; // Esto ha hecho una copia amigo!
    c1.ingresar(cantidad);

    cout << "despues del ingreso en la funcion vale " << endl;
    mostrar(c1);
};

void procesarRetirada(Cuenta *c) {

    float cantidad;

    cout << "Introduce la cantidad a retirar ";
    cin >> cantidad;

    Cuenta c1 = *c;
    c1.retirar(cantidad);
};

int main(int argc, char *argv[]) {

    Cuenta c1;

    c1.titular = "Barbie";

    c1.saldo = 100;

    // c1 = c2;

    mostrar(c1);

    procesarIngreso(&c1);
    procesarRetirada(&c1);

    mostrar(c1);
    // cout << "La cuenta de " << c1.titular << " tiene " << c1.saldo << " euros " << endl;
    // cout << "La cuenta de " << c2.titular << " tiene " << c2.saldo << " euros " << endl;
}
