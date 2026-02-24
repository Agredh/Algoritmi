// Somma alternata dei primi n interi positivi. Scrivere una funzione ricorsiva che calcoli la somma alternata
// dei primi n interi positivi:
//                                  S(n) = 1-2+3-4+------+-n.
// (Suggerimento): la regola può essere espressa come 
//                                  S(n) = S(n-1) + (-1)^n+1 * n.
#include <iostream>
#include <cmath>
using namespace std;

int serie_Alterna(int n) {
    if (n==1) return 1;

    return pow(-1, n+1) * n + serie_Alterna(n-1);
}

int main() {
    cout << serie_Alterna(4) << endl;
}