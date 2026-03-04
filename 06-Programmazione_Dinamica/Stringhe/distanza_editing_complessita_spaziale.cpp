// Risoluzione problema di ottimizzazione distanza di editing, nel caso non si fosse interessati
// a trovare la risoluzione ottima risparmiando spazio.

#include <iostream>
using namespace std;

int editing_distance_friend(const string, const string);
void print_array(const int *, const int);
int min(int, int, int);


int main(void) {
    string first_word = "chiese";
    string second_word = "casa";

    int distance = editing_distance_friend(first_word, second_word);
    cout << "La distanza di editing tra " << first_word << " e "
         << second_word << " è pari a " << distance << endl;
}

int editing_distance_friend(const string x, const string y) {
    int n = x.length() + 1;
    int m = y.length() + 1;
    int *riga1 = new int[m];
    int *riga2 = new int[m];

    for (int i=0; i<m; i++) {
        riga1[i] = i;
    } 

    for (int i=1; i<n; i++) {
        riga2[0] = i;

        for (int j=1; j<m; j++) {

            if (x[i-1] == y[j-1]) {
                riga2[j] = riga1[j-1];
            }
            else {
                riga2[j] =1 + min(riga2[j-1], riga1[j], riga1[j-1]);
            }
        }
        
        int *tmp = riga1;
        riga1 = riga2;
        riga2 = tmp;
    }
    return riga1[m-1];
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

void print_array(const int *a, const int n) {
    if (n==0) return;

    print_array(a, n-1);
    cout << a[n-1] << "  ";
}