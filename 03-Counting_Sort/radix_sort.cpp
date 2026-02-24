#include <iostream>
using namespace std;

void counting_sort(int *, const int, const int);
void print_array(const int *, const int);
void radix_sort(int *, const int, const int);
int potenza_10(int);

int main(void) {
    int A[] = {329, 457, 657, 839, 436, 720, 355};
    const int N = 7;
    const int H = 3;

    cout << endl;
    print_array(A, N);
    cout << endl;
    radix_sort(A, N, H);
    print_array(A, N);
    cout << endl;
}

int potenza_10(int esponente) {
    if (esponente == 0) return 1;

    return 10 * potenza_10(esponente-1);
}

void counting_sort(int *a, const int n,  const int esponente) {
    int k = 10;
    int *c = new int[k];
    int *b = new int[n];
    int potenza = potenza_10(esponente);

    for (int i=0; i<k; i++) {
        c[i] = 0;
    }

    int cifra = 0;
    for (int i=0; i<n; i++) {
        cifra = a[i] / potenza % 10;
        c[cifra] += 1;
    }

    for (int i=1; i<=k; i++) {
        c[i] = c[i-1] + c[i];
    }
 
    for (int i=n-1; i>=0; i--) {
        cifra = a[i] / potenza % 10;
        c[cifra]--;
        b[c[cifra]] = a[i];
    }

    for (int i=0; i<n; i++) {
        a[i] = b[i];
    }
}

void radix_sort(int *a, const int n, const int cifre) {
    for (int i=0; i<cifre; i++) {
        counting_sort(a, n, i);
    }
}

void print_array(const int *a, const int n) {
    if (n== 0) return; 

    print_array(a, n-1);
    cout << a[n-1] << "   ";
}