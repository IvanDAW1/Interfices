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

    Cuenta c1("Juanito", "001");
    // Cuenta c2 ("Pepito", "002",100);
    mostrar(c1);
    cout << endl;
    // procesarIngreso(&c1);
    // bloquearc1
    c1.estado = Cuenta::BLOQUEADO;
    cout << "Bloqueada" << endl;
    procesarIngreso(&c1);
    cout << endl;
    // limitarc1
    c1.estado = Cuenta::LIMITADO;
    cout << "Limitada" << endl;
    procesarIngreso(&c1);
    cout << endl;
    mostrar(c1);
    cout << endl;
    procesarRetirada(&c1);
    cout << endl;
    mostrar(c1);
    cout << endl;
    // cout << "La cuenta de " << c1.titular << " tiene " << c1.saldo << " euros " << endl;
    // cout << "La cuenta de " << c2.titular << " tiene " << c2.saldo << " euros " << endl;
}
