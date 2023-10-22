#include <iostream>
#include "cuenta.h"

void Cuenta::ingresar(float cantidad) {
    if (estado == BLOQUEADO) return;
    if (cantidad >= 0) saldo += cantidad;
}

Cuenta::Cuenta() {
    estado = OPERATIVA;
}

Cuenta::Cuenta(string tit, string num, float saldoIn) : numCuenta(num), titular(tit), saldo(saldoIn) {
    estado = OPERATIVA;
}

bool Cuenta::retirar(float cantidad) {
    if (estado != OPERATIVA) return false;
    if (cantidad > saldo) return false;
    saldo -= cantidad;
    return true;
}

void Cuenta::transferir(Cuenta *destino) {
    destino->ingresar(saldo);
    retirar(saldo);
}

void Cuenta::operator>>(Cuenta &destino) {
    destino.ingresar(saldo);
    retirar(saldo);
}
