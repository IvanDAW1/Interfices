#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int numero = 0;
    int numeroSecreto = 3;
    int contador = 0;

    while (true) {
        cout << "Dime un número : ";
        cin >> numero;
        cout << "El número es " << numero << endl;
        contador++;
        if (numero == numeroSecreto)
            break;
        if (numero < numeroSecreto)
            cout << "El número secreto es mayor" << endl;
        else
            cout << "El número secreto es menor" << endl;
    }

    cout << "Has acertado el número" << endl;
    cout << "Nuero de intentos " << contador << endl;
}
