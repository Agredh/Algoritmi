#include <iostream>
using namespace std;

void counting_sort(int *, const int);
void print_array(const int *, const int);
int get_max(const int *, const int);

int main(void) {
    const int N = 9;
    int A[] = {4,3,5,3,5,3,2,3,4};

    cout << endl;
    print_array(A, N);
    cout << endl;
    counting_sort(A, N);
    print_array(A, N);
    cout << endl;
}

void counting_sort(int *array, const int dim) {
    int k = get_max(array, dim) + 1;
    int *b = new int[dim];
    int *c = new int[k];

    for (int i=0; i<=k; i++) {
        c[i] = 0;
    }

    for (int i=0; i<dim; i++) {
        c[array[i]] += 1;
    }

    for (int i=1; i<=k; i++) {
        c[i] = c[i-1] + c[i];
    }

    for (int i=dim-1; i>= 0; i--) {
        c[array[i]] -= 1;
        b[c[array[i]]] = array[i];
    }

    for (int i=0; i<dim; i++) {
        array[i] = b[i];
    }

    delete b;
}

void print_array(const int *array, const int dim) {
    if (dim == 0) return; 

    print_array(array, dim-1);
    cout << array[dim-1] << "   ";
}

int get_max(const int *array, const int dim) {
    if (dim == 1) return array[0];

    int max = get_max(array, dim-1);
    return ((array[dim-1] > max) ? array[dim-1] : max);
}