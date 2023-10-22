#include <iostream>

using namespace std;

class Cuenta {

public:
    string numCuenta;
    string titular;
    float saldo;

    enum Estado {
        BLOQUEADO,
        LIMITADO,
        OPERATIVA
    };

    Estado estado;

    Cuenta() {
        estado = OPERATIVA;
    }

    Cuenta(string tit, string num, float saldoIn = 0.00f) : numCuenta(num), titular(tit), saldo(saldoIn) {

        estado = OPERATIVA;
    }

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
        destino->ingresar(saldo);
        retirar(saldo);
    }

    void operator>>(Cuenta &destino) {
        destino.ingresar(saldo);
        retirar(saldo);
    }
};

void mostrar(Cuenta c) {

    cout << "La cuenta de " << c.titular << " tiene " << c.saldo << " euros " << endl;
};

void procesarIngreso(Cuenta *pc) {

    if (pc->estado != Cuenta::BLOQUEADO) {

        float cantidad;
        cout << "Introduce la cantidad a ingresar ";
        cin >> cantidad;
        pc->ingresar(cantidad);
    } else {

        cout << "La cuenta está bloqueada\nNo se ha realizado la operación" << endl;
        cout << endl;
    }
};

void procesarRetirada(Cuenta *c) {

    if (c->estado != Cuenta::OPERATIVA) {

        cout << "La cuenta está bloqueada o limitada\nNo se ha realizado la operación" << endl;
        cout << endl;
    } else {

        float cantidad;
        cout << "Introduce la cantidad a retirar ";
        cin >> cantidad;
        c->retirar(cantidad);
    }
};

void transferir(Cuenta *origen, Cuenta *destino) {

    (*destino).ingresar((*origen).saldo);
    (*origen).retirar((*origen).saldo);
}

int main(int argc, char *argv[]) {

    Cuenta c1("Juanito", "001", 100);
    Cuenta c2("Pepito", "002", 200);

    c1 >> c2;
    mostrar(c1);
    mostrar(c2);
}
