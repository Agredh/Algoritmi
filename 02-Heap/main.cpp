// Main Prova Heap
#include <iostream>
#include <cstdlib>
#include "Max_Heap.h"
#include "Coda_Priorita.h"
#include "Heap.h"
using namespace std;

void print_array(const int*, const int);

int main() {
    /* Prova Max_heap
    Max_Heap<int> *heap = new Max_Heap<int>();
    const int N = 10;
    int *array = new int[N];

    srand(time(NULL));
    for (int i=0; i<N; i++) {
        array[i] = rand() % 50 + 1;
    }

    print_array(array, N);
    heap->heapsort(array, N);
    print_array(array, N);
    */

    Coda_Priorita<int> *coda = new Coda_Priorita<int>(2);
    coda->insert(5);
    coda->insert(6);
    coda->insert(7);
    coda->print_coda();
    coda->extract_max();
    coda->print_coda();
    coda->extract_max();
    coda->print_coda();
    coda->extract_max();
    coda->print_coda();
}

void print_array(const int *array, const int N) {
    cout << endl;

    for (int i=0; i<N; i++) {
        cout << array[i] << "  ";
    }

    cout << endl;
}