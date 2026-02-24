#include <iostream>
using namespace std;

void selection_sort(int *, int);
void selection_sort_ricorsivo(int *, int, int);
int find_min(int *, int, int);
int find_min_r(int *, int, int);
void print(int *, int, int);
void swap(int &, int &);

int main() {
    const int N = 5;
    int array[] = {64, 25, 12, 22, 11};
    cout << "Array prima dell'ordinamento:\n";
    print(array, N, 0);
    cout << "Array post ordinamento:\n";
    selection_sort_ricorsivo(array, N, 0);
    print(array, N, 0);
}

void selection_sort(int *A, int n) {
    for (int i=0; i<n; i++) {
        int min = find_min(A, n, i);
        swap(A[i], A[min]);
    }
}

void selection_sort_ricorsivo(int *A, int n, int start) {
    if (start >= n-1) return;

    int j = find_min(A, n, start);
    swap(A[j], A[start]);
    selection_sort_ricorsivo(A, n, start+1);
}

void print(int *A, int n, int indice) {
    if (indice >= n) {
        cout << "\n";
        return;
    }
    cout << A[indice] << "  ";
    print(A, n, indice+1);
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int find_min(int *A, int n, int start) {
    int min = start;

    for (int i=start+1; i<n; i++) {
        if (A[min] > A[i]) {
            min = i;
        }
    }

    return min;
}

int find_min_r(int *A, int n, int start) {
    if (start >= n-1) return start;

    int min = find_min_r(A, n, start+1);
    return (A[min] < A[start]) ? min : start;
}