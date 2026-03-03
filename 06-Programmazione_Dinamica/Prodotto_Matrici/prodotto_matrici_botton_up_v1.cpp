// Risoluzione problema di ottimizzazione trovare parentesizzazione per effettuare il minore numero
// di moltiplicazioni per il calcolo del prodotto tra n matrici, con approccio top-down
#include <iostream>
#include <climits>
using namespace std;

int matrix_chain_order_botton_up_v1(const int *, const int);
//void print_matrix(int**, const int);

int main(void) {
    int dimensioni[] = {30,35,15,5,10,20,25};
    const int N = 7;

    int numero_minimo_operazione = matrix_chain_order_botton_up_v1(dimensioni, N-1);
    cout << "Il numero di moltiplicazioni minime da eseguire è " 
         << numero_minimo_operazione << endl;
}

int matrix_chain_order_botton_up(const int *p, const int n) {
    int **S = new int*[n+1];
    for (int i=0; i<=n; i++) {
        S[i] = new int[n+1];
    }

    for (int i=0; i<=n; i++) {
        S[i][i] = 0;
    }

    for (int l=2; l<=n; l++) {
        for (int i=1; i<=n-l+1; i++) {
            int j = i + l - 1;
            S[i][j] = INT_MAX;

            for (int k=i; k<j; k++) {
                if (S[i][j] > S[i][k] + S[k+1][j] + (p[i-1]*p[k]*p[j])) {
                    S[i][j] = S[i][k] + S[k+1][j] + (p[i-1]*p[k]*p[j]);
                }
            }
        }
    }

    return S[1][n];
}

/*
void print_matrix(int **p, const int n) {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            cout << p[i][j] << "  ";
        }
        
        cout << endl;
    }
}
*/