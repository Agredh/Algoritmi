// Funzione ricorsiva per il calcola dell'i-esimo numero della sequenza di Fibonacci con approccio botton-up
#include <iostream>
using namespace std;

int fibonacci_botton_up(const int);

int main(void) {
    int indice = 10;
    
    cout << "Fibonacci(" << indice << ") = " << fibonacci_botton_up(indice) << endl;
}

int fibonacci_botton_up(const int n) {
    int *array = new int[n];

    if (n >= 1) {
        array[0] = 1;

        if (n >= 2) {
            array[1] = 1;
        }
    }

    for (int i=2; i<n; i++) {
        array[i] = array[i-1] + array[i-2];
    }

    return array[n-1];
}