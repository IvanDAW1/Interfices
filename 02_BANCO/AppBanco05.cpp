#include <iostream>
#include <sstream>
#include <vector>
#include "cuenta.h"

using namespace std;

void mostrar(Cuenta c) {
    cout << "";
    cout << "La cuenta de " << c.titular << " con el id " << c.numCuenta << " tiene " << c.saldo << " euros " << endl;

};

void procesarIngreso(Cuenta *pc) {

    if (pc->estado != Cuenta::BLOQUEADO) {
        float cantidad;
        cout << "Introduce la cantidad a ingresar : ";
        cin >> cantidad;
        cout << endl;
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

void inicializar(vector<Cuenta> *cuentas) {
    string nombres[5] = {"juan", "perico", "andres", "fulano", "vengano"};
    for (int i = 0; i < 5; i++) {
        Cuenta cuenta;
        cuenta.titular = nombres[i];
        stringstream ss;
        ss << 100 + i;
        string numCuenta = ss.str();
        cuenta.numCuenta = numCuenta;
        cuenta.saldo = i * 100;
        cuentas->push_back(cuenta);
    }
}

void mostrarCuentas(vector<Cuenta> cuentas) {

    for (int i = 0; i < cuentas.size(); ++i) {
        mostrar(cuentas[i]);
    }
}

Cuenta *seleccionarCuentas(vector<Cuenta> *cuentas) {

    string numeroCuenta;
    cout << "Dime el número de cuenta que deseas seleccionar: ";
    cin >> numeroCuenta;
    cout << endl;

    for (int i = 0; i < cuentas->size(); ++i) {
        if (numeroCuenta == cuentas->at(i).numCuenta) {
            return &(cuentas->at(i));
        }
    }

    /*
    for (auto & cuenta : *cuentas) {
        if (numeroCuenta == cuenta.numCuenta) {
            return &cuenta;
        }
    }

     ES IGUAL
    */
    return NULL;
}

int main(int argc, char *argv[]) {

    vector<Cuenta> cuentas;

    inicializar(&cuentas);
    mostrarCuentas(cuentas);

    Cuenta *cuentaSeleccionada = seleccionarCuentas(&cuentas);
    procesarIngreso(cuentaSeleccionada);
    mostrarCuentas(cuentas);

}