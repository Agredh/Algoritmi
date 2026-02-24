#include <iostream>
#include <stdexcept>
using namespace std;

template<class T, int Capacity> class Max_Heap {
    private:
        T heap[Capacity];
        int heap_Size;

        int parent(int i) {return i/2;}
        int left_Child(int i) {return 2 * i;}
        int right_Child(int i) {return 2*i + 1;}

        void max_Heapify(int i) {
            int left = left_Child(i);
            int right = right_Child(i);
            int max = i;

            if (left<heap_Size && heap[max]<heap[left]) {
                max = left;
            }

            if (right<heap_Size && heap[max]<heap[right]) {
                max = right;
            }

            if (max != i) {
                swap(heap[max], heap[i]);
                max_Heapify(max);
            }
        }

        void heapify_Up(int i) {
            while (i>1 && heap[parent(i)]<heap[i]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

    public:
        Max_Heap() : heap_Size(1) {}

        void insert(T key) {
            if (heap_Size >= Capacity) {
                throw overflow_error("Heap is full");
            }

            heap[heap_Size] = key;
            /*          Equivalente funzione heapify_Up(heap_Size)
            int i = heap_Size-1;
            while (i>1 && heap(parent(i))) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
            */
            heapify_Up(heap_Size);
            heap_Size++;
        }

        T estrai_massimo() {
            if (heap_Size <= 1) {
                throw out_of_range("Heap is empty");
            }

            T max = heap[1];
            heap[1] = heap[heap_Size-1];
            heap_Size--;
            max_Heapify(1);
            return max;
        }

        T get_Max() const {
            if (heap_Size <= 1) 
                throw out_of_range("Heap is empty");

            return heap[1];
        }

        void print() const {
            for (int i=1; i<heap_Size; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    const int CAPACITY = 10;
    Max_Heap<int, CAPACITY> mh;
    mh.insert(3);
    mh.insert(2);
    mh.insert(15);
    mh.insert(5);
    mh.insert(4);
    mh.insert(45);

    std::cout << "Heap: ";
    mh.print();

    std::cout << "Max: " << mh.get_Max() << std::endl;
    std::cout << "Extract Max: " << mh.estrai_massimo() << std::endl;

    std::cout << "Heap after extract: ";
    mh.print();

    return 0;
}