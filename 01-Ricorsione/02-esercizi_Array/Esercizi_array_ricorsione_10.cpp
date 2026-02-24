// Prodotto alternato degli elementi. Scrivere una funzione ricorsiva che calcoli il prodotto alternato degli elementi 
// di un array A, moltiplicando il primo, dividendo per il secondo, moltiplicando per il terzo e così via.
// Suggerimento: applicare a ciascun elemento un segno alternato (-1)^i nel calcolo logaritmico o equivalente.
#include <iostream>
#include <cmath>
using namespace std;

int prodotto_alternato(const int array[], const int dim) {
    if (dim == 0) return 1;

    return pow(-1, dim) * array[dim-1] * prodotto_alternato(array, dim-1);
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[] = {1,1,1,1,1,1,1,2,1,1};
    
    cout << "\nArray: ";
    stampa_array(A, N);
    cout << "\nIl prodotto alternato dell'array è: " << prodotto_alternato(A, N) << endl << endl;
}