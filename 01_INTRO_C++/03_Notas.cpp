#include <iostream>

using namespace std;

void inicializar(int notasPasadas[10]) {

    for (int i = 0; i < 10; i++) {
        int unaNota = rand();
        notasPasadas[i] = unaNota % 100;
    }

    // notasPasadas[1] = 0;
}

void mostrarNotas(int notasPasadas[10]) {

    for (int i = 0; i < 10; i++) {
        cout << notasPasadas[i] << " ";
    }
    cout << endl;
}

int buscaMax(int notasPasadas[10]) {

    int notaAlta = notasPasadas[0];

    for (int i = 0; i < 10; i++) {
        if (notasPasadas[i] > notaAlta)
            notaAlta = notasPasadas[i];
    }
    return notaAlta;
}

int cuantos(int notas[10], int nota) {
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (notas[i] == nota) {
            count++;
        }
    }
    return count;
}

bool existe(int notas[10], int nota) {

    return cuantos(notas, nota) > 0;
}

bool repite(int notas[10], int nota) {

    for (int i = 1; i < 10; i++) {
        if (notas[i] == nota && notas[i - 1] == nota) {
            return true;
        }
    }

    return false;
}

bool repiteNotas(int notas[10]) {

    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++)
            if (notas[i] == notas[j])
                return true;

    return false;
}

int mediaNotas(int notas[10]) {

    // Esta mal

    int notasAltas[4];
    int notaAlta = notas[0];
    int notasTotal = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (notas[j] > notaAlta)
                notaAlta = notas[j];
        }
        for (int r = 0; i < 10; i++) {
            if (notas[r] == notaAlta)
                notas[r] = 0;
        }

        notasTotal += notaAlta;
        notaAlta = 0;
    }

    return notasTotal;
}

int main(int argc, char const *argv[]) {
    int notas[10];
    int max;

    inicializar(notas);
    mostrarNotas(notas);
    max = buscaMax(notas);

    cout << "La nota mas alta es : " << max << endl;

    if (existe(notas, 6)) {
        cout << "El alumno ha sacado un 6" << endl;

        cout << "El alumno ha sacado " << cuantos(notas, 6) << " seis" << endl;;
    }

    if (repite(notas, 4)) {
        cout << "El alumno ha sacado dos 4 seguidos " << endl;
    }

    if (repiteNotas(notas)) {
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }
    // Media de las 4 notas mas altas
    int media = mediaNotas(notas);

    cout << "La media de las 4 notas mas altas es " << media << endl;
}
