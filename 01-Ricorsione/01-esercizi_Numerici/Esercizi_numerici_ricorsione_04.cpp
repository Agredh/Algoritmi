// Massimo Comune Divisore (MCD). Scrivere una funzione ricorsiva che calcoli il massimo comune divisore tra
// due numeri interi positivi a e b. (Suggerimento): utilizzate la relazione MCD(a, b) = MCD(b, a%b)
#include <iostream>
using namespace std;

int MCD(int a, int b) {
    if (b==0) return a;

    return MCD(b, a%b);
}

int main() {
    cout << MCD(2, 5) << endl;
}