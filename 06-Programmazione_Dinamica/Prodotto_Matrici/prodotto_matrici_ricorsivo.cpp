// Risoluzione problema di ottimizzazione trovare parentesizzazione per effettuare il minore numero
// di moltiplicazioni per il calcolo del prodotto tra n matrici
#include <iostream>
#include <climits>
using namespace std;

int matrix_chain_order(const int *, const int, const int);

int main(void) {
    int dimensioni[] = {30,35,15,5,10,20,25};
    const int N = 7;

    int numero_minimo_operazione = matrix_chain_order(dimensioni, 1, N-1);
    cout << "Il numero di moltiplicazioni minime da eseguire è " 
         << numero_minimo_operazione << endl;
}

int matrix_chain_order(const int *p, int i, int j) {
    if (i == j) return 0;

    int min = INT_MAX;
    for (int k=i; k<j; k++) {
        int sik = matrix_chain_order(p, i, k);
        int skj = matrix_chain_order(p, k+1, j);
        int tmp = sik + skj + (p[i-1] * p[k] * p[j]);

        if (tmp < min) {
            min = tmp;
        }
    }

    return min;
}