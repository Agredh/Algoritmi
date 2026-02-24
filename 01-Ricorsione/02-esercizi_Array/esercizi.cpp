#include <iostream>
#include <cmath>
using namespace std;

////////////////
// Esercizio01//
////////////////
int number_Of_Negative(int *A, int n) {
    if (n<0) return 0;

    return (A[n] < 0) ? 1 + number_Of_Negative(A, n-1) : number_Of_Negative(A, n-1);
}



////////////////
// Esercizio02//
////////////////
int prodotto_Pari(int *A, int n) {
    if (n==0) return 1;

    return (A[n-1] % 2 == 0) ? A[n-1] * prodotto_Pari(A, n-1) : prodotto_Pari(A, n-1);
}



////////////////
// Esercizio03//
////////////////
int media(int *A, int n) {
    int media=0;
    
    for (int i=0; i<n; i++) {
        media += A[i];
    }

    return media / n;
}

int up_Media(int *A, int n, int media) {
    if (n==0) return 0;

    return (A[n-1] > media) ? 1 + up_Media(A, n-1, media) : up_Media(A, n-1, media);
}



////////////////
// Esercizio04//
////////////////
int differenza_Somme_Pari_Somme_Dispari(int *A, int n) {
    if (n==0) return 0;

    return pow(-1, n) * A[n-1] + differenza_Somme_Pari_Somme_Dispari(A, n-1);
}



////////////////
// Esercizio05//
////////////////
bool simmetria(int *A, int n) {
    if (n==0) return;
    
    cout << *A << " ";
    simmetria(A+1, n-1);
}

int main() {
    const int N = 9;
    int A[] = {1,2,3,4,5,4,3,2,1};

    simmetria(A, N);
}