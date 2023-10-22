#include <stdlib.h>
#include <iostream>

using namespace std;

void hazNegativo(int *punteroI) {

    //*punteroI = (*punteroI-*punteroI-*punteroI);
    //*punteroI = (*punteroI-((*punteroI)*2));
    *punteroI = -abs(*punteroI);
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
    int j;

    i = 8;
    j = 9;

    int *pi = &i;
    int *pj = &j;

    int *pmax;

    pmax = maximo(pi, pj);

    *pmax = 100;

    // int *p = &i;
    // hazNegativo( p ); //referencia a i

    cout << " El nuevo valor de i es " << i << endl;
    cout << " El nuevo valor de j es " << j << endl;
    cout << " El nuevo valor de pmax es " << pmax << endl;
}