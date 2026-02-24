// Successione di Fibonacci. Scrivere una funzione ricorsiva che calcoli il termine n-esimo della successione di Fibonacci.
// (Suggerimento): la successione è definita da F(n) = F(n-1) + F(n-2).
#include <iostream>
using namespace std;

int fibo(int n) {
    if (n==0) return 0;
    if (n==1) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main() {
    cout << fibo(7) << endl;
}