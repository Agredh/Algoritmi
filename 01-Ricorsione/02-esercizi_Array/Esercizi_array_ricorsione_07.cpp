// Calcolo del valore medio ricorsivo. Scrivere una funzione ricorsiva che calcoli la media aritmetica degli elementi
// di un array A di lunghezza n.
// (Suggerimento): restituite la media come combinazione della somma parziale e del numero di elementi elaborati.
#include <iostream>
using namespace std;

float calcola_media(const int *array, int dim) {
    if (dim == 1) return array[0];

    return ((float) (calcola_media(array, dim-1) * (dim-1) + array[dim-1]) / dim);
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "\nArray: ";
    stampa_array(A, N);
    cout << "\nIl valore della media dell'array è: " << calcola_media(A, N) << endl << endl;
}