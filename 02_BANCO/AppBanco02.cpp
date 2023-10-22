#include <iostream>
#include <sstream>
#include "cuenta.h"

using namespace std;

void mostrar(Cuenta c) {

    cout << "La cuenta de " << c.titular << " con el id " << c.numCuenta << " tiene " << c.saldo << " euros " << endl;

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

void inicializar(Cuenta cuentas[5]) {
    string nombres[5] = {"juan", "perico", "andres", "fulano", "vengano"};
    for (int i = 0; i < 5; i++) {
        cuentas[i].titular = nombres[i];
        stringstream ss;
        ss << 100 + i;
        string numCuenta = ss.str();
        cuentas[i].numCuenta = numCuenta;
        cuentas[i].saldo = i * 100;
    }
}

void mostrarCuentas(Cuenta cuentas[5]) {
    for (int i = 0; i < 5; ++i) {
        mostrar(cuentas[i]);
    }
}

Cuenta * seleccionarCuentas(Cuenta cuentas[5]) {

    int numero;
    string numeroCuenta;
    cout << "Dime el numero de la cuenta que deseas ingresar el dinero : ";
    cin >> numeroCuenta;

    for (int i = 0; i < 5; ++i) {
        if (cuentas[i].numCuenta == numeroCuenta) {
            return &cuentas[i];
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    Cuenta cuentas[5];
    inicializar(cuentas);
    mostrarCuentas(cuentas);

    Cuenta *cuentaSeleccionada = seleccionarCuentas(cuentas);
    procesarIngreso(cuentaSeleccionada);
    mostrarCuentas(cuentas);

}