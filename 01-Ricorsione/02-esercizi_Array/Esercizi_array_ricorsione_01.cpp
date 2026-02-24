// Conteggio dei valori negativi. Scrivere una funzione ricorsiva che conti quanti elementi di un 
// array A di lunghezza n sono minori di zero. (Suggerimento): sommare 1 se A[i] < 0 e procedere 
// con l'array rimanente.
#include <iostream>
using namespace std;

int numeroElemnetiNegativi(int *array, int dim) {
    if (dim==0) return 0;

    return ((array[dim - 1] < 0) ? 1 : 0) + numeroElemnetiNegativi(array, dim-1);
}

void stampaArray(int *array, int dim) {
    if (dim == 0) return;

    stampaArray(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[] = {-1,-2,3,-4,5,6,7,8,9,-10};

    stampaArray(A, N);
    cout << "\nIl numero di elementi negativi nell'array è: " 
         << numeroElemnetiNegativi(A, N) << endl;
}