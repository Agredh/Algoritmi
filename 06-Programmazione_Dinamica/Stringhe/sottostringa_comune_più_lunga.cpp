// Risoluzione problema di ottimizzazione di ricerca di una sottosequenza comune più lunga, 
// con metodo per costruzione della soluzione.
#include <iostream>
using namespace std;

int lcs(string, string);
int **lcs_index(string, string);
void build_lcs(string, string);
void print_matrix(int **, const int, const int);

int main(void) {
    string x = "atgccat";
    string y = "ggccaa";
   
    int lunghezza = lcs(x, y);
    cout << "La più lunga sottostringa comune a " << x 
         << " e " << y << "é lunga " << lunghezza << endl;

    cout << "La sottostringa più lunga è: ";
    build_lcs(x, y);
    cout << endl;
}

int lcs(string x, string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;

    int **lcs = new int*[n];
    for (int i=0; i<n; i++) {
        lcs[i] = new int[m];
    }

    for (int j=0; j<m; j++) {
        lcs[0][j] = 0;
    }

    for (int i=0; i<n; i++) {
        lcs[i][0] = 0;
    }

    int max = 0;

     for (int i=1; i<n; i++) {
        
        for (int j=1; j<m; j++) {
            
            if (x[i-1] == y[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];

                if (max < lcs[i][j]) {
                    max = lcs[i][j];
                }
            }
            else {
                lcs[i][j] = 0;
            }
        }
    }

    print_matrix(lcs, n, m);
    return max;
}  

int **lcs_index(string x, string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;

    int **lcs = new int*[n];
    for (int i=0; i<n; i++) {
        lcs[i] = new int[m];
    }

    for (int j=0; j<m; j++) {
        lcs[0][j] = 0;
    }

    for (int i=0; i<n; i++) {
        lcs[i][0] = 0;
    }

    int max = 0;
    int maxi, maxj;

     for (int i=1; i<n; i++) {
        
        for (int j=1; j<m; j++) {
            
            if (x[i-1] == y[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];

                if (max < lcs[i][j]) {
                    max = lcs[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
            else {
                lcs[i][j] = 0;
            }
        }
    }

    lcs[0][0] = maxi;
    lcs[0][1] = maxj; 
    return lcs;
}

void print_matrix(int **p, const int n, const int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << p[i][j] << "  ";
        }
        
        cout << endl;
    }
}

void build_lcs(string x, string y) {
    int **lcs = lcs_index(x,y);
    int maxi = lcs[0][0]; 
    int maxj = lcs[0][1];
    lcs[0][0] = 0;
    lcs[0][1] = 0;

    string sottostringa_reverse = "";
    while (lcs[maxi][maxj] > 0) {
        sottostringa_reverse += x[maxi-1];
        maxi -= 1;
        maxj -= 1;
    }

    cout << sottostringa_reverse;
    for (int i=sottostringa_reverse.length(); i>=0; i--) {
        cout << sottostringa_reverse[i] << " ";
    }
}