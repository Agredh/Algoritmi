// Verifica della presenza di una sottosequenza crescente. Scrivere una funzione ricorsiva che verifichi se all'interno di un 
// array A esiste una sequenza di almeno tre elementi consecutivi in ordine strettamente crescente. La funzoine deve restituire 
// true o false.
// (Suggerimento): mantenere un contatore che si incrementa finchè la sequenza è crescente e si azzera in caso contrario.
#include <iostream>
using namespace std;

bool esiste_sottosequenza_crescente(const int *array, const int dim, int counter) {
    
    if (counter == 3) {
        return true;
    }

    if (dim == 1) {
        return (counter >=3) ? true : false;
    }

    if (array[dim-1] > array[dim-2]) {
        counter++;
    }
    else {
        counter = 1;
    }

    return esiste_sottosequenza_crescente(array, dim-1, counter);
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[] = {1,2,3,2,1,2,1,2,1,2};
    
    cout << "\nArray: ";
    stampa_array(A, N);
    cout << "\nL'array" << (esiste_sottosequenza_crescente(A, N, 1) ? "" : " non") << " ha una sottosequenza crescente\n\n";
}