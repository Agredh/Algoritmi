//Risoluzione problema del taglio delle aste per massimizzare guadagno sulle vendite con approccio
// approccio iterativo botton-up, con metodo stampa soluzione ottima
#include <iostream>
#include <climits>
using namespace std;

int *cut_rod_iterative(const int *, const int);
void print_cut_rod(const int *, int);
void print_array(const int *, const int);

int main(void) {
    const int DIM = 10;
    const int costo_vendita[] = {0,1,5,8,9,10,17,17,20,24,30};

    print_cut_rod(costo_vendita, DIM);
}

int *cut_rod_iterative(const int *p, const int n) {
    int *s = new int[2 * n + 1];
    s[0] = 0;

    for (int j=1; j<=n; j++) {
        int q = INT_MIN;

        for (int i=1; i<=j; i++) {
            int tmp = p[i] + s[j-i];
            
            if (q < tmp) {
                q = tmp;
                s[n+j] = i;
            }
        }

        s[j] = q;
    }

    return s;
}
 
void print_cut_rod(const int *p, int n) {
    int *r = cut_rod_iterative(p,n);
    int *s = new int [n+1];

    s[0] = 0;
    for (int i=1; i<=n; i++) {
        s[i] = r[n+i];
    }

    delete []r;

    while (n>0) {
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}

void print_array(const int *p, const int n) {
    int dim = 2*n+1;

    for (int i=0; i<dim; i++) {
        cout << p[i] << endl;
    }
}