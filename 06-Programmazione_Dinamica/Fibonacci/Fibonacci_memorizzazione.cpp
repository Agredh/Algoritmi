// Funzione ricorsiva per il calcola dell'i-esimo numero della sequenza di Fibonacci con memorizzazione
#include <iostream>
using namespace std;

int fibonacci_Memorizzazione(const int, int *);
int *inizializza_array(const int);
void print_array(const int *, const int);

int main(void) {
    int indice = 10;
    int *array = inizializza_array(indice);
    //print_array(array, indice);

    cout << "Fibonacci(" << indice << ") = " << fibonacci_Memorizzazione(indice, array) << endl;
    //print_array(array, indice);
    //cout << endl;
}

int fibonacci_Memorizzazione(const int n, int *a) {
    if (a[n-1] != 0) 
        return a[n-1];

    if (a[n-2] == 0) {
        a[n-2] = fibonacci_Memorizzazione(n-1, a);
    }

    return a[n-2] + a[n-3];
}

int *inizializza_array(const int n) {
    int *M = new int[n];
    
    if (n>=1) {
        M[0] = 1;

        if (n>=2) M[1] = 1;
    }

    for (int i=3; i<n; i++) {
        M[i] = 0;
    }

    return M;
}

void print_array(const int *a, const int n) {
    if (n==0) return;

    print_array(a, n-1);
    cout << a[n-1] << "  ";
}