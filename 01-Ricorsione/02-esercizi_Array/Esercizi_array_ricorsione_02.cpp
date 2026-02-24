// Prodotto dei valori pari. Scrivere una funzione ricorsiva che calcoli il prodotto di tutti gli elementi
// pari di un array A di lunghezza n. Se l'array non contiene elementi pari, la funzione deve resituire 1.
// (Suggerimento): verificare la condizione A[i] mod 2 = 0 prima di moltiplicare
#include <iostream>
using namespace std;

int number_of_even(int *array, int dim) {
    if (dim == 0) return 1;

    return ((array[dim-1] % 2 == 0) ? array[dim-1] : 1) * number_of_even(array, dim-1); 
}

void stampaArray(int *array, int dim) {
    if (dim == 0) return;

    stampaArray(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[N] = {2,2,3,3,5,5,7,3,9,10};

    stampaArray(A, N);
    cout << "\nIl prodotto degli elementi pari nell'array è: " 
         << number_of_even(A, N) << endl;
}