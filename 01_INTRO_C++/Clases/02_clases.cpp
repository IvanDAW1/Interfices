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

    Cuenta c1, c2;

    c1.tituar = "Barbi";
    c2.tituar = "Ken";

    c1.saldo = 100;
    c2.saldo = 200;

    c1 = c2;
    c2.ingresar(500);

    cout << "El saldo de la cuenta de " << c1.tituar << " es " << c1.saldo << endl;
    cout << "El saldo de la cuenta de " << c2.tituar << " es " << c2.saldo << endl;
}