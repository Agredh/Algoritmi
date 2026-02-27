// Risoluzione problema del taglio delle aste per massimizzare guadagno sulle vendite con ricorsione semplice
#include <iostream>
#include <climits>

using namespace std;

int cut_rod(const int *, const int);
int max(int, int);

int main(void) {
    const int DIM = 10;
    const int costo_vendita[] = {1,5,8,9,10,17,17,20,24,30};

    int guadagno=cut_rod(costo_vendita, DIM);
    cout << "Il ricavo massimo da un asta di dimensione " << DIM 
         << " è pari a " << guadagno << endl;
}

int cut_rod(const int *p, const int n) {
    if (n==0) return 0;

    int q = INT_MIN;
    for (int i=0; i<n; i++) {
        q = max(q, p[i]+cut_rod(p, n-1-i));
        //cout << "q: " << q << endl;
    }

    return q;
}

int max(int a, int b) {
    if (a>b) return a;

    return b;
}