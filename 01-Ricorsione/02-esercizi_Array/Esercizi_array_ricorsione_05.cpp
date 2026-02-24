// Verifica di simmetria. Scrivere una funzione ricorsiva che determini se un array A di lunghezza n
// è simmetrico rispetto al suo centro, cioè A[i] = A[n-1-i] per ogni i. La funzione deve restituire 
// true o false. (Suggerimento): confrontare gli elementi alle estremità e ridurre il problema escludendo 
// e l'ultima posizione.
#include <iostream>
using namespace std;

bool simmetria(const int *array, const int dim, int i) {
    int j = dim - 1;

    if (i >= j) return true;
    
    if (array[i] == array[j]) {
        return simmetria(array, dim-1, i+1);
    }

    return false;
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 9;
    int A[] = {1,2,3,4,5,4,3,3,1};
    
    cout << "\nArray: ";
    stampa_array(A, N);
    cout << "\nL'array " << ((simmetria(A, N, 0)) ? "" : "non") << " è simmetrico" << endl << endl;
}