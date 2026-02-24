// Somma delle cifre di un numero. Scrivete una funzione ricorsiva che calcoli la somma delle cifre di un numero intero 
// positivo n. (Suggerimento): l'ultima cifra di n può essere ottenuta con n mod 10.
#include <iostream>
using namespace std;

int somma_Cifre(int n) {
    if (n == 0) return 0;

    return n % 10 + somma_Cifre(n/10);
}

int main() {
    cout << somma_Cifre(9) << endl;
}