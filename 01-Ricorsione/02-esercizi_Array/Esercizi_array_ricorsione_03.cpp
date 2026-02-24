// Conteggio dei valori superiori alla media. Scrivere una funzione ricorsiva che conti quanti elementi di un 
// array A di lunghezza n hanno valore superiore alla media aritmetica dell'array stesso.
// (Suggerimento): calcolare prima la media con una funzione separata e utilizzarla come paramentro nella 
// chiamata ricorsiva principale.
#include <iostream>
using namespace std;

int numero_valori_maggiori_media(const int *array, const int dim, const float media) {
    if (dim == 0) return 0;

    return ((media < array[dim-1]) ? 1 : 0) + numero_valori_maggiori_media(array, dim-1, media);
}

float calcola_media(const int *array, const int dim) {
    int somma = 0;
    for (int i=0; i<dim; i++) {
        somma += array[i];
    }

    return (float) somma / dim;
}

void stampa_array(const int* array, const int dim) {
    if (dim == 0) return;

    stampa_array(array, dim-1);
    cout << array[dim-1] << "  ";
}

int main(void) {
    const int N = 10;
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    float media = calcola_media(A, N);

    cout << "\nArray\n";
    stampa_array(A, N);
    cout << "\nIl valore della media per l'array è: " << media << endl;
    cout << "Il numero di elementi superiori alla media è: " << numero_valori_maggiori_media(A, N, media) << endl << endl;
}