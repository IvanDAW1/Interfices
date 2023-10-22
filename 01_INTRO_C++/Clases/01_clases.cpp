#include <iostream>

using namespace std;

class Cuenta {
private:
    // float saldo;

public:
    string numCuenta;
    string tituar;
    float saldo;

    void ingresar(float cantidad) {
        if (cantidad > 0)
            saldo += cantidad;
    }

    bool retirar(float cantidad) {
        if (saldo >= cantidad) {
            saldo = saldo - cantidad;
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {

    Cuenta c;
    c.tituar = "Juan";
    c.numCuenta = "ES12";
    c.saldo = 21.23;

    c.ingresar(1000);
    c.retirar(299);

    cout << "El saldo de la cuenta de " << c.tituar << " es " << c.saldo << endl;

    if (c.retirar(1000)) {
        cout << "He retirado 1000 euros" << endl;
    } else {
        cout << "No he podido retirar lo que no debía" << endl;
    }
}