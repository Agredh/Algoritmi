// Conteggio dei divisori di un numero. Scrivere una funzione ricorsiva che conti quanti interi positivi dividono
// esattamente un dato numero n. (Suggerimento): verificare se n mod k = 0 per un divisore candidato k decrescente.
#include <iostream>
using namespace std;

int dividers(int n, int k) {
    if (k==1) return 1;

    return (n % k == 0) ? 1 + dividers(n, k-1) : dividers(n, k-1);
}

int main() {
    cout << dividers(9, 9) << endl;
}