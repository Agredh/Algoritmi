// Funzione ricorsiva per il calcola dell'i-esimo numero della sequenza di Fibonacci
#include <iostream>
using namespace std;

int Fibonacci(const int);

int main(void) {
    int indice = 10;

    cout << "Fibonacci(" << indice << ") = " << Fibonacci(indice) << endl;
}

int Fibonacci(const int n) {
    if (n <= 2) return 1;

    return Fibonacci(n-1) + Fibonacci(n-2);
}