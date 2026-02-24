// Differenza tra somma dei pari e somma dei dispari. Scrivere una funzione ricersiva che calcoli la differenza tra la somma
// degli elementi pari e la somma degli elementi dispari di un array A di lunghezza n.
// (Suggerimento): usare una ricorsione unica in cui ogni elemento contribuisce con segno positivo o negativo a seconda della
// sua parità.
#include <iostream>
using namespace std;

int differenza_somma_pari_somma_dispari(const int *array, const int dim) {
    if (dim == 0) return 0;

    int parita = array[dim-1] % 2;
    return ((parita) ? -1 : 1) * array[dim-1] + differenza_somma_pari_somma_dispari(array, dim-1); 
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
    cout << "\nLa differenza tra la somma degli elementi con valore pari e la somma di quelli con" 
         << " valore dispari è: " << differenza_somma_pari_somma_dispari(A, N) << endl << endl;
}