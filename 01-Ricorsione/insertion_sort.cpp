#include <iostream>
using namespace std;

void insertion_sort(int array[], int dim);
void insertion_sort_ricorsivo(int array[], int dim);
void print(int array[], int dim);
void print_r(int array[], int dim);
void swap(int &, int &);

int main() {
    const int N = 5;
    int array[] = {64, 25, 12, 22, 11};
    cout << "Array prima dell'ordinamento:\n";
    print(array, N);
    cout << "\n\nArray post ordinamento:\n";
    insertion_sort_ricorsivo(array, N);
    print_r(array, N);
    cout << endl;
}

void insertion_sort(int array[], int dim) {

    int j;
    for (int i=1; i<dim; i++) {
        j = i;

        while (j>0 && array[j] < array[j-1]) {
            swap(array[j], array[j-1]);
            j--;
        }
    }
}

void insertion_sort_ricorsivo(int array[], int dim) {
    if (dim == 1) return;

    insertion_sort_ricorsivo(array, dim-1);
    int j = dim-1;
    
    while (j>0 && array[j] < array[j-1]) {
        swap(array[j], array[j-1]);
        j--;
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print(int array[], int dim) {
    
    for (int i=0; i<dim; i++) {
        cout << array[i] << "  ";
    }
}

void print_r(int array[], int dim) {
    if (dim == 0) return;

    print_r(array, dim-1);
    cout << array[dim-1] << "  ";
}