#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int numero = 0;
    int numeroSecreto = 3;
    int contador = 0;

    for (; numero != numeroSecreto; cout << "Dime un número : ",
            cin >> numero,
            cout << "El número es " << numero << endl,
            contador++);
    {
        if (numero < numeroSecreto)
            cout << "El número secreto es mayor" << endl;
        if (numero > numeroSecreto)
            cout << "El número secreto es menor" << endl;
    };

    cout << "Has acertado el número" << endl;
    cout << "Nuero de intentos " << contador << endl;
}