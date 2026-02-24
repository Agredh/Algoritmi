// Conteggio valori unici. Scrivere una funzione ricorsiva che conti quanti elementi di un array A non si ripetono.
// Un elemento è detto univoco se compare una sola volta nell'array.
// Suggerimenti: confrontare ogni elemento con i restanti e proseguire riducendo l'array.
#include <iostream>
using namespace std;

int conta_occorrenze(const int *array, const int dim, const int value) {
    if (dim == 0) {
        return 0;
    }

    return ((value == array[dim-1]) ? 1 : 0) + conta_occorrenze(array, dim-1, value);
}

int numero_elementi_unici(const int *array, const int dim) {
    int unici = 0;

    for (int i=0; i<dim; i++) {
        
        if (conta_occorrenze(array, dim, array[i]) == 1) {
            unici++;
        }
    }

    return unici;
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
    cout << "\nIl numero di elementi unici dell'array è: " << numero_elementi_unici(A, N) << endl << endl;
}