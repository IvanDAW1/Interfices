#include <iostream>

using namespace std;

class Cuenta {

public:

    string numCuenta;
    string titular;
    float saldo;

    enum Estado {
        BLOQUEADO, LIMITADO, OPERATIVA
    };
    Estado estado;

    Cuenta();

    Cuenta(string tit, string num, float saldoIn = 0.00f);

    void ingresar(float cantidad);

    bool retirar(float cantidad);

    void transferir(Cuenta *destino);

    void operator>>(Cuenta &destino);

};
