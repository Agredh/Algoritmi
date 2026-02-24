// Somma dei primi numeri dispari. Scrivere una funzione ricorsiva che calcoli la somma dei primi 
// n numeri dispari. (Suggerimento): l'ultimo termine può essere espresso come 2n-1.
#include <iostream>
using namespace std;

int somma(int n) {
    if (n == 1) return 1;
    
    int p = 2 * n - 1;                                  // calcola l'n-esimo numero dispari
    return p + somma(n-1);
}

int main() {
    cout << somma(3) << endl;
}