#include <stdlib.h>
#include <iostream>

using namespace std;

void hazNegativo(int *punteroI) {

    *punteroI = -abs(*punteroI);
}

void hazNegativo2(int &num) {
    num = -abs(num);
}

int *maximo(int *p1, int *p2) {

    if (*p1 > *p2)
        return p1;
    else
        return p2;
}

int &maximo2(int &p1, int &p2) {
    if (p1 > p2)
        return p1;
    else
        return p2;
}

int main(int argc, char *argv[]) {

    char c;

    int i = 80;
    int j = 70;
    int o = 8;

    hazNegativo2(o);

    cout << " El nuevo valor de i es " << o << endl;

    int &pmax = maximo2(i, j);
    cout << " El nuevo valor de pmax es " << pmax << endl;
    pmax = 100;

    cout << " El nuevo valor de i es " << i << endl;
    cout << " El nuevo valor de j es " << j << endl;
    cout << " El nuevo valor de pmax es " << pmax << endl;

}