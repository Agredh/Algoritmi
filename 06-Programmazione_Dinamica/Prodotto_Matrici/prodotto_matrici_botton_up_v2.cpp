// Risoluzione problema di ottimizzazione trovare parentesizzazione per effettuare il minore numero
// di moltiplicazioni per il calcolo del prodotto tra n matrici, con approccio top-down e 
// costruzione soluzione ottima
#include <iostream>
#include <climits>
using namespace std;

int **matrix_chain_order_botton_up(const int *, const int);
void print_optimal_parens(int **, const int, const int);


int main(void) {
    int dimensioni[] = {30,35,15,5,10,20,25};
    const int N = 7;

    int **numero_minimo_operazione = matrix_chain_order_botton_up(dimensioni, N-1);
    cout << "Il numero di moltiplicazioni minime da eseguire è " 
         << numero_minimo_operazione[N-1][0] << endl;

    print_optimal_parens(numero_minimo_operazione, 0, N-1);
    cout << endl;
}

int **matrix_chain_order_botton_up(const int *p, const int n) {
    int **m = new int*[n+1];
    for (int i=0; i<=n; i++) {
        m[i] = new int[n+1];
    }

    // è possibile non creare una nuova matrica in cui conservare gli indici k, basterebbe utilizzare
    // la porzione di matrice m vuota sotto la diagonale principale semplicemente invertendo 
    // gli indici i e j quando conserviamo il valore dell'indice k
    int **s = new int*[n+1];
    for (int i=0; i<=n; i++) {
        s[i] = new int[n+1];
    }

    for (int l=2; l<=n; l++) {
        for (int i=1; i<=n-l+1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k=i; k<j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < m[i][j]) {
                    m[i][j] = q; 
                    s[i][j] = k;
                }
            }
        }
    }

    s[n][0] = m[1][n];
    return s;
}

void print_optimal_parens(int **s, const int i, const int j) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        cout << ")";
    }
}