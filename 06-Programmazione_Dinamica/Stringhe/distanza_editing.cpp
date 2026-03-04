// Risoluzione problema di ottimizzazione distanza di editing
#include <iostream>
using namespace std;

int **editing_distance(const string, const string);
void print_edt(const string, const string);
void print_matrix(int **, const int, const int);
int min(int, int, int);

int main(void) {
    string first_word = "chiese";
    string second_word = "casa";

    int **distance = editing_distance(first_word, second_word);
    cout << "La distanza di editing tra " << first_word << " e "
         << second_word << " è pari a " << distance[first_word.length()][second_word.length()] << endl;

    print_edt(first_word, second_word);
}

int **editing_distance(const string x, const string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;
    int **ed = new int *[n];
    for (int i=0; i<n; i++) {
        ed[i] = new int[m];
    }

    for (int i=0; i<m; i++) {
        ed[0][i] = i;
    }

    for (int i=0; i<n; i++) {
        ed[i][0] = i;
    }

    for (int i=1; i<n; i++) {
        
        for (int j=1; j<m; j++) {

            if (x[i-1] == y[j-1]) {
                ed[i][j] = ed[i-1][j-1];
            }
            else {
                ed[i][j] = 1 + min(ed[i-1][j], ed[i][j-1], ed[i-1][j-1]);
            }
        }
    }

    print_matrix(ed, n, m);

    return ed;
}   

void print_edt(const string x, const string y) {
    int **ed = editing_distance(x, y);
    int i = x.length();
    int j = y.length();

    while (ed[i][j] > 0) {
        
        if (x[i-1] == y[j-1]) {
            i--;
            j--;
        }
        else {
            int op = min(ed[i-1][j], ed[i][j-1], ed[i-1][j-1]);

            if (op == ed[i][j-1]) {
                j--;
                cout << "Inserito " << y[j] << " in " << x << endl;
            }
            else if (op == ed[i-1][j]) {
                i--;
                cout << "cancellato " << x[i] << endl;
            }
            else {
                i--;
                j--;
                cout << "sostituito " << x[i] << " con " << y[j] << endl;
            }
        }
    }
}

void print_matrix(int **matrix, const int n, const int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int min(int a, int b, int c) {
    int minimo = a;

    if (minimo > b) {
        minimo = b;
    }

    if (minimo > c) {
        minimo = c;
    }

    return minimo;
}