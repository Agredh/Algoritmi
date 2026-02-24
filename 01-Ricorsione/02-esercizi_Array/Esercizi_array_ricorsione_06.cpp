// Conteggio dei picchi locali. Scrivere una funzione ricorsiva che conti quanti elementi di un array A sono 
// picchi locali, ossia valore tali che A[i] > A[i-1] e A[i] > A[i+1].
// (Suggerimento): limitare la ricorsione agli indici interni dell'array e verificare la condizione di massimo
// relativo.
#include <iostream>
using namespace std;

int numero_picchi_locali(int *array, int dim) {
    if (dim == 0) return 0;
    
    int i = dim-1;
    return ((array[i] > array[i-1] && array[i] > array[i+1]) ? 1 : 0 ) + numero_picchi_locali(array, dim-1);
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 9;
    int A[] = {1,10,3,4,7,4,5,8,1};
    
    cout << "\nArray: ";
    stampa_array(A, N-1);
    cout << "\nIl numero di picchi locali dell'array è: " << numero_picchi_locali(A, N-1) << endl << endl;
}