#include <iostream>
#include "cuenta.h"
#include <sstream>

using namespace std;

void mostrar(Cuenta c) {

    cout << "La cuenta de " << c.titular << " tiene " << c.saldo << " euros " << c.numCuenta << endl;
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

/*
void operator >> (Cuenta &c1, Cuenta &c2){
float saldo = c1.saldo;

	c1.retirar(c1.saldo);
	c2.ingresar(saldo);
}*/

void transferir(Cuenta *origen, Cuenta *destino) {

    (*destino).ingresar((*origen).saldo);
    (*origen).retirar((*origen).saldo);
}


void inicializar(Cuenta cuentas[5]) {
    string nombres[5] = {"Juan", "Perico", "Andrés", "Fulano", "Vengano"};

    for (int i = 0; i < 5; i++) {
        cuentas[i].titular = nombres[i];
        stringstream ss;
        ss << 100 + i;
        string numCuenta = ss.str();
        cuentas[i].numCuenta = numCuenta;
        cuentas[i].saldo = i * 100;
    }
}

void inicializar2(Cuenta *cuentas[5]) {
    string nombres[2] = {"Juan", "Perico"};

    for (int i = 0; i < 2; i++) {

        Cuenta *nueva = new Cuenta();
        nueva->titular = nombres[i];
        stringstream ss;
        ss << 100 + i;
        string numCuenta = ss.str();
        nueva->numCuenta = numCuenta;
        nueva->saldo = i * 100;

        cuentas[i] = nueva;
    }
}

void mostrar(Cuenta *cuentas[5]) {

    for (int i = 0; i < 5; i++) {
        if (cuentas[i] != NULL) {
            mostrar(*cuentas[i]);
        }
    }
}

Cuenta *seleccionarCuenta(Cuenta *cuentas[5]) {
    string cuentaSolicitada;
    cout << "Dime el numero de cuenta: ";
    cin >> cuentaSolicitada;

    for (int i = 0; i < 5; i++) {

        if (cuentas[i] != NULL && cuentas[i]->numCuenta == cuentaSolicitada) return cuentas[i];
    }

    return NULL;
}

void agregarCuenta(Cuenta *cuentas[5]) {

    for (int i = 0; i < 5; i++) {
        if (cuentas[i] == NULL) {
            cuentas[i] = new Cuenta("PEPE", "102", 10);
            break;
        }
    }
}

int main(int argc, char *argv[]) {

    Cuenta *cuentas[5];

    for (int i = 0; i < 5; i++) cuentas[i] = NULL;

    inicializar2(cuentas);
    mostrar(cuentas);
    agregarCuenta(cuentas);
    mostrar(cuentas);

    Cuenta *pCuenta = seleccionarCuenta(cuentas);
    if (pCuenta != NULL)
        procesarIngreso(pCuenta);
    else
        cout << "El numero de cuenta no existe" << endl;
    mostrar(cuentas);

}