// Heap Binario implementato tramite un array
#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

class Heap {
    private:
        int *heap;
        int size;
        int heapsize;

        int get_parent(int i) { return i >> 1; }
        int get_left(int i) { return i << 1; }
        int get_rigth(int i) { return (i << 1) + 1; }

        // supponendo che i sottoalberi sinistro e destro di un nodo i siano due max_heap fa si che 
        // la proprietà di max heap sia rispettata dal nodo i
        void max_heapify(int i) {
            int l = get_left(i);
            int r = get_rigth(i);
            int max = i;

            if (l <= heapsize && heap[l] > heap[max]) {
                max = l;
            }

            if (r <= heapsize && heap[r] > heap[max]) {
                max = r;
            }

            if (i != max) {
                swap(heap[i], heap[max]);
                max_heapify(max);
            }
        }

        // Funzione di utilità utile per mantenere proprietà di un min_heap.
        void min_heapify(int i) {
            int l = get_left(i);
            int r = get_rigth(i);
            int min = i;

            if (l <= heapsize && heap[l] < heap[min]) {
                min = l;
            }

            if (r <= heapsize && heap[r] < heap[min]) {
                min = r;
            }

            if (i != min) {
                swap(heap[min], heap[i]);
                min_heapify(min);
            }
        }

        // trasforma heap in un max_heap
        void build_max_heap() {
            for (int i=heapsize/2; i >= 1; i--) {
                max_heapify(i);
            }
        }

        // trasforma heap in un min_heap
        void build_min_heap() {
            for (int i=heapsize/2; i >= 1; i--) {
                min_heapify(i);
            }
        }


        void swap(int &a, int &b) { 
            int tmp = a; 
            a = b; 
            b = tmp;
        }


    public:
        Heap() {
            this->size = 100;
            this->heapsize = 0;
            heap = new int(100);
        }

        // setta heap con un array passato dal main
        void set_heap(int *array, int dim) { 
            this->size = dim+1; 
            this->heapsize = dim;
            this->heap = new int(size);

            // riempie l'heap con gli elementi di array a partire dall'indice 1;
            for (int i=1; i<size; i++) {
                heap[i] = array[i-1];
            }
        }

        // ordina un array
        void heap_sort(int *array, int dim) {
            set_heap(array, dim);
            build_max_heap();

            for (int i=heapsize; i>=2; i--) {
                swap(heap[1], heap[i]);
                heapsize--;
                max_heapify(1);
            }

            // copia gli elementi di heap in array a partire dall'indice 0
            for (int i=0; i<dim; i++) {
                array[i] = heap[i+1];
            }
        }

        // restituisce l'elemento massimo in un max_heap
        int max() { 
            if (heapsize >= 1)
                return heap[1];
            cout << "La coda è vuota!" << endl << endl;
            return -1;
        }

        // restituisce il minimo in un min_heap
        T min() { 
            if (heapsize >= 1)
                return heap[1];
            throw out_of_range("Errore; non ci sono elementi nell'heap!\n");
        }

        // estrae elemento massimo in un max_heap
        int extract_max() {
            if (heapsize < 1) {
                throw out_of_range("Errore; non ci sono elementi nell'heap!\n");
            }

            int max = heap[1];
            heap[1] = heap[heapsize];
            heapsize--;
            max_heapify(1);

            return max;
        }

        // estrae elemento minimo in un min_heap
        int extract_min() {
            if (heapsize < 1) {
                throw out_of_range("Errore; non ci sono elementi nell'heap!\n");
            }

            int min = heap[1];
            heap[1] = heap[heapsize];
            heapsize--;
            min_heapify(1);

            return min;
        }

        // incrementa il valore di una chiave, necessario per implementare una coda con priorità
        void increase_key(int i, int key) {
            if (heap[i] > key) {
                cout << "Errore, la chiave inserita è maggiore del valore originale!" << endl << endl;
                return;
            }

            heap[i] = key;
            
            while (i>1 && heap[i]>heap[get_parent(i)]) {
                swap(heap[i], heap[get_parent(i)]);
                i = get_parent(i);
            }
        }

        // decrementa il valore di una chiave
        void decrease_key(int i, int key) {
            if (heap[i] < key) {
                cout << "Errore, la chiave inserita è minore dle valore originale!" << endl << endl;
                return;
            }

            heap[i] = key;

            while (i>1 && heap[i]<heap[get_parent(i)]) {
                swap(heap[i], heap[get_parent(i)]);
                i = get_parent(i);
            }
        }

        // inserisce un elemento in un max_heap
        void insert_max_heap(int key) {
            if (heapsize >= size)
                throw overflow_error("L'heap è pieno\n");

            heapsize++;
            heap[heapsize] = INT_MIN;
            increase_key(heapsize, key);
        }

        // inserisce un elemento in un min_heap
        void insert_min_heap(int key) {
            if (heapsize >= size)
                throw overflow_error("L'heap è pieno\n");

            heapsize++;
            heap[heapsize] = INT_MAX;
            decrease_key(heapsize, key);
        }

        // Stampa l'heap
        void print() {
            for (int i=1; i<=heapsize; i++) {
                cout << heap[i] << "   ";
            }

            cout << endl << endl;
        }
};