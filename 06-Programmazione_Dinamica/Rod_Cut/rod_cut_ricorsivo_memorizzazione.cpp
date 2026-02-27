// Risoluzione problema del taglio delle aste per massimizzare guadagno sulle vendite tramite ricorsione con memorizzazione
#include <iostream>
#include <climits>

using namespace std; 

int cut_rod_memorizzazione(const int *, const int);
int cut_rod_memorizzazione_aux(const int *, const int, int *);
int max(int, int);

int main(void) {
    const int DIM = 10;
    const int costo_vendita[] = {0,1,5,8,9,10,17,17,20,24,30};

    int guadagno=cut_rod_memorizzazione(costo_vendita, DIM);
    cout << "Il ricavo massimo da un asta di dimensione " << DIM 
         << " è pari a " << guadagno << endl;
}

int cut_rod_memorizzazione(const int *p, const int n) {
    int *r = new int[n+1];

    for (int i=0; i<=n; i++) {
        r[i] = INT_MIN;
    }

    return cut_rod_memorizzazione_aux(p, n, r);
}

int cut_rod_memorizzazione_aux(const int *p, const int n, int *r) {
    if (r[n] >= 0) {
        return r[n];
    }

    int q;
    if (n==0) {
        q = 0;
    }
    else {
        q = INT_MIN;
        for (int i=1; i<=n; i++) {
            q = max(q, p[i]+cut_rod_memorizzazione_aux(p, n-i, r));
        }

    }

    r[n] = q;
    return q;
}

int max(int a, int b) {
    if (a>b) return a;

    return b;
}