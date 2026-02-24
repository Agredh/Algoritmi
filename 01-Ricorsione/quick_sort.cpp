#include <iostream>
using namespace std;

void print_r(int A[], int dim);
void swap(int &, int &);
int partition(int [], int, int);
void quick_sort(int [], int, int);

int main() {
    const int N = 5;
    int array[] = {64, 25, 12, 22, 11};
    cout << "Array prima dell'ordinamento:\n";
    print_r(array, N);
    cout << "\n\nArray post ordinamento:\n";
    quick_sort(array, 0, N);
    print_r(array, N);
    cout << endl << endl;
}

void print_r(int A[], int dim) {
    if (dim == 0) return;

    print_r(A, dim-1);
    cout << A[dim-1] << "  ";
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void quick_sort(int A[], int low, int high) {

    if (low < high) {
        int pi = partition(A, low, high);

        quick_sort(A, low, pi-1);
        quick_sort(A, pi+1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        
        if (A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    
    swap(A[i+1], A[high]);
    return i+1;
}