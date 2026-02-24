// Prodotto dei primi numeri dispari. Scrivere una funzione ricorsiva che calcoli il prodotto dei primi n numeri
// dispari positivi. (Suggerimento): l'ultimo termine della sequenza è 2n-1.
#include <iostream>
using namespace std;

int prodotto_primi_N_interi(int n) {
    if (n == 1) return 1;

    int p = 2 * n - 1;
    return p * prodotto_primi_N_interi(n-1);
}

int main(void) {
    const int N = 3;
    cout << "Prodottoo primi " << N 
         << " numeri naturali: " << prodotto_primi_N_interi(N) << endl;
}