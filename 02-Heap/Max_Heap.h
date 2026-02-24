#include <iostream>

template <class T> class Max_Heap {
    private:
        T *heap;
        int heapsize;
        int size;

        void set_heap(const int *array, const int dim) {
            this->heapsize = dim;
            this->size = dim+1;
            this->heap = new T[size];

            for (int i=0; i<dim; i++) {
                heap[i+1] = array[i];
            }
        }

        void print_heap() {
            for (int i=0; i<=heapsize; i++) {
                std::cout << heap[i] << "  ";
            }
        }

        int parent(int i) { return i >> 1; }

        int left(int i) { return i << 1; }

        int right(int i) { return (i << 1) + 1; }

        void max_heapify(int i) {
            int l = left(i);
            int r = right(i);
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

        void swap(T &a, T &b) {
            T tmp = a;
            a = b;
            b = tmp;
        }

        void build_max_heap() {
            for (int i=heapsize/2; i>=1; i--) {
                max_heapify(i);
            }
        }

    public:
        Max_Heap() {
            this->heap = NULL;
            int size = 0;
            int heapsize = 0;
        }

        Max_Heap(const int *array, const int dim) {
            set_heap(array, dim);
        }

        void heapsort(int *array, int dim) {
            set_heap(array, dim);
            build_max_heap();

            for (int i=heapsize; i>=2; i--) {
                swap(heap[1], heap[i]);
                heapsize--;
                max_heapify(1);
            }

            for (int i=0; i<dim; i++) {
                array[i] = heap[i+1];
            }
        }
};