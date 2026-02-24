#include <iostream>
using namespace std;

void print_r(int array[], int dim);
void merge_sort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);

int main() {
    const int N = 5;
    int array[] = {64, 25, 12, 22, 11};
    cout << "Array prima dell'ordinamento:\n";
    print_r(array, N);
    cout << "\n\nArray post ordinamento:\n";
    merge_sort(array, 0, N);
    print_r(array, N);
    cout << endl;
}

void print_r(int array[], int dim) {
    if (dim == 0) return;

    print_r(array, dim-1);
    cout << array[dim-1] << "  ";
}

void merge_sort(int array[], int l, int r) {
    if (l >= r) return;

    int m = l + (r-l) / 2;

    merge_sort(array, l, m);
    merge_sort(array, m+1, r);

    merge(array, l, m, r);
}

void merge(int array[], int l, int m, int r) {
    int dim1 = m - l + 1;
    int dim2 = r - m;
    int left[dim1], right[dim2];
    
    // Riempie l'array ausiliario con la sottoparte di sinistra ordinata
    for (int i=0; i<dim1; i++) {
        left[i] = array[l+i];
    }

    // Riempie l'array ausiliario con la sottoparte di destra ordinata
    for (int j=0; j<dim2; j++) {
        right[j] = array[m+j+1];
    }

    // Merge dei due sotto array
    int i=0, j=0, k=l;  
    while (i<dim1 && j<dim2) {
        
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }

        k++;
    }

    //Riempi array con i restanti elementi
    while (i < dim1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < dim2) {
        array[k] = right[j];
        j++;
        k++;
    }
}