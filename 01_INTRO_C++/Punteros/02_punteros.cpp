#include <stdlib.h>
#include <iostream>

using namespace std;

void hazNegativo(int *punteroI) {

    //*punteroI = (*punteroI-*punteroI-*punteroI);
    //*punteroI = (*punteroI-((*punteroI)*2));
    *punteroI = -abs(*punteroI);
}

void hazNegativo2(int &num) {
    num = -abs(num);
}

int *maximo(int *p1, int *p2) {

    if (*p1 > *p2) {
        //*p1 = 100;
        return p1;
    } else {
        //*p2 = 100;
        return p2;
    }
}

int main(int argc, char *argv[]) {

    char c;

    int i;
    int m = 70;
    int &j = i;

    i = 80;

    hazNegativo2(i);

    cout << " El nuevo valor de i es " << i << endl;
    cout << " El nuevo valor de j es " << j << endl;

    i = 23;

    cout << " El nuevo valor de i es " << i << endl;
    cout << " El nuevo valor de j es " << j << endl;

    j = 29;

    cout << " El nuevo valor de i es " << i << endl;
    cout << " El nuevo valor de j es " << j << endl;

    cout << " Posicion en memoria " << &i << endl;
    cout << " Posición en memoria " << &j << endl;
}