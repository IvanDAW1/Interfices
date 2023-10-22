#include <iostream>

using namespace std;

class Cuenta {

public:
    string numCuenta;
    string titular;
    float saldo;

    Cuenta(string numCuneta1, string titular1, float saldoinicial = 0) {
        numCuenta = numCuneta1;
        titular = titular1;
        saldo = saldoinicial;
    }

    Cuenta() {}

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

    void transferir(Cuenta *destino) {
        (*destino).ingresar(saldo);
        retirar(saldo);
    }
};

int main(int argc, char const *argv[]) {

    Cuenta cuenta("pepe", "lol", 23);
    Cuenta cuenta2("hola", "awd");

    cout << cuenta.saldo << endl;
    cout << cuenta2.saldo << endl;
}
