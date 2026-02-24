#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

template<class T> class Coda_Priorita {
    private:
        int size;
        int heapisize;
        T *heap;

        int left(int i) { return i << 1; }

        int right(int i) { return (i << 1) + 1; }

        int parent(int i) { return i >> 1; }

        void max_heapify(int i) {
            int l = left(i);
            int r = right(i);
            int max = i;

            if (l <= heapisize && heap[l] > heap[max]) {
                max = l;
            }

            if (r <= heapisize && heap[r] > heap[max]) {
                max = r;
            }

            if (i != max) {
                swap(heap[i], heap[max]);
                max_heapify(max);
            }
        }

        void swap(int &a, int &b) {
            int tmp = a; 
            a = b; 
            b = tmp;
        }

    public:
        Coda_Priorita() {
            this->size = 100;
            this->heapisize = 0;
            heap = new T[size];

            for (int i=0; i<size; i++) {
                heap[i] = 0;
            }
        }

        Coda_Priorita(int dim) {
            this->size = dim;
            this->heapisize = 0;
            heap = new T[size];

            for (int i=0; i<size; i++) {
                heap[i] = 0;
            }
        }

        T get_max() {
            if (heapisize >= 1)
                return heap[1];

            throw out_of_range("Errore; non ci sono elementi nell'heap!\n");
        }

        T extract_max() {
            if (heapisize < 1) {
                throw out_of_range("Errore; non ci sono elementi nell'heap!\n");
            }

            T max = heap[1];
            heap[1] = heap[heapisize];
            heapisize--;
            max_heapify(1);
            return max;  
        }

        void increase_key(int i, int k) {
            if (k < heap[i]) { 
                cout << "Errore, la chiave" << k << "inserita è inferiore al valore attuale!\n";
                return;
            }

            heap[i] = k;

            while (i>1 && heap[i] > heap[parent(i)]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void insert(int k) {
            if (heapisize >= size) {
                cout << "Errore! Impossibile inserire la chiave " << k << " la coda è piena.\n";
                return;
            }

            heapisize++;
            heap[heapisize] = INT_MIN;
            increase_key(heapisize, k);
        }

        void print_coda() {
            cout << endl;

            for (int i=1; i<=heapisize; i++) {
                cout << heap[i] << "   ";
            }

            cout << endl << endl;
        }
};