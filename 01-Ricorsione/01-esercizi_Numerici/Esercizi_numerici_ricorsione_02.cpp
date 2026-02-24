// Conteggio delle cifre di un numero. Scrivete una funzione ricorsiva che, dato un numero intero positivo n,
// restituisca il numero di cifre che lo compongono. (Suggerimento): dividere n per 10 a ogni passo riduce di
// una cifra il numero.
#include <iostream>
using namespace std;

int n_Cifre(int n) {
    if (n == 0) return 0;

    return 1 + n_Cifre(n/10);
}

int main() {
    cout << n_Cifre(1024) << endl;
}