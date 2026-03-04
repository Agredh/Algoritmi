// Problema di ottimizzazione della ricerca della sottosequenza
// più lunga.
#include <iostream>
using namespace std;

int lcs_length(const string, const string);
int **lcs_matrix(const string, const string);
void _print_lcs(const string, const string , int **, int, int);
void print_lcs(const string, const string);
void print_matrix(int **, const int, const int);
int max(int, int);

int main(void) {
    string x = "ACTAAA";
    string y = "CCATAG";

    int lunghezza_lcs = lcs_length(x,y);
    cout << "La lunghezza della sottosequenza più lunga tra la stringa " << x 
         << "e la stringa " << y << " è " << lunghezza_lcs << endl;

    cout << "La sottosequenza più lunga è: ";
    print_lcs(x, y);
}

int lcs_length(const string x, const string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;
    int **lcs = new int*[n];
    for (int i=0; i<n; i++) {
        lcs[i] = new int[m];
    }

    for (int i=0; i<n; i++) {
        lcs[i][0] = 0;
    }

    for (int j=0; j<m; j++) {
        lcs[0][j] = 0;
    }

    for (int i=1; i<n; i++) {
        
        for (int j=1; j<m; j++) {

            if (x[i-1] == y[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }

    print_matrix(lcs, n, m);

    return lcs[n-1][m-1];
}

int **lcs_matrix(const string x, const string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;
    int **lcs = new int*[n];
    for (int i=0; i<n; i++) {
        lcs[i] = new int[m];
    }

    for (int i=0; i<n; i++) {
        lcs[i][0] = 0;
    }

    for (int j=0; j<m; j++) {
        lcs[0][j] = 0;
    }

    for (int i=1; i<n; i++) {
        
        for (int j=1; j<m; j++) {

            if (x[i-1] == y[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }

    return lcs;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void print_matrix(int **a, const int n, const int m) {
    for (int i=0; i<n; i++) {

        for (int j=0; j<m; j++) {
            cout << a[i][j] << "  ";
        }

        cout << endl;
    }
}   

void print_lcs(const string x, const string y) {
    int **lcs = lcs_matrix(x, y);
    int i = x.length();
    int j = y.length();

    _print_lcs(x, y, lcs, i, j);
    cout << endl;
}

void _print_lcs(const string x, const string y, int **lcs, int i, int j) {
    if (lcs[i][j] == 0) return;
    
    if (x[i-1] == y[j-1]) {
        _print_lcs(x,y,lcs,i-1,j-1);
        cout << x[i-1] << " ";
    }
    else if (lcs[i][j] == lcs[i-1][j]) {
        _print_lcs(x,y,lcs,i-1,j);
    }
    else {
        _print_lcs(x,y,lcs,i,j-1);
    }
}