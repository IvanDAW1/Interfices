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

void mostrar(Cuenta c) {
    cout << "El saldo de la cuenta de " << c.tituar << " es " << c.saldo << " euros" << endl;
}

void procesarIngreso(Cuenta c) {

    float cant;
    cout << "Dime el saldo a ingresar en la cuenta" << endl;
    cin >> cant;
    c.ingresar(cant);
    cout << "El ingreso a sido un exito" << endl;
    cout << "Tu nuevo saldo es de " << c.saldo << " de euros" << endl;
}

void procesarRetirada(Cuenta c) {
    float cant;
    cout << "Dime la cantidad de saldo que deseas retirar" << endl;
    cin >> cant;
    if (c.retirar(cant)) {
        cout << "El saldo se ha retirado con exito" << endl;
    };
    cout << "No se ha podido retirar el saldo con exito" << endl;
}

int main(int argc, char const *argv[]) {

    Cuenta c1, c2;

    c1.tituar = "Barbi";
    c2.tituar = "Ken";

    c1.saldo = 100;
    c2.saldo = 200;

    c1 = c2;
    c2.ingresar(500);

    mostrar(c1);
    mostrar(c2);

    procesarIngreso(c1);
    procesarIngreso(c1);
}
