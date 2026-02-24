#ifndef HASH_APERTO_H
#define HASH_APERTO_H
#include <iostream>
#include <functional>

template<class T> class Hash_Aperto {
    private:
        int dimensione;
        T *table;

        int hashing_divisione(T key) {
            int h = std::hash<T>{}(key) % dimensione;
            return (h < 0) ? h + dimensione : h;
        }

        int ispezione_lineare(T key, int i) {
            return (hashing_divisione(key) + i) % dimensione;
        }

    public: 
        Hash_Aperto(int dimensione) {
            this->dimensione = dimensione;
            table = new T[dimensione];

            for (int i=0; i<dimensione; i++) {
                table[i] = -1;
            }
        }

        Hash_Aperto<T> *hash_insert(T key) {
            int i=0;
            int j = ispezione_lineare(key, i);

            while (i<dimensione && table[j]!=-1) {
                i++;
                j = ispezione_lineare(key, i);
            }

            if (i<dimensione) {
                table[j] = key;
            }
            else {
                std::cout << "Impossibile inserire una chiave, heap pieno!\n";
            }

            return this;
        }

        int get_index(T key) {
            int i = 0; 
            int j = ispezione_lineare(key, i);

            while (i<dimensione && table[j] != -1) {
                if (table[j] == key) return j;
                
                i++;
                j = ispezione_lineare(key, i);
            }

            return -1;
        }

        bool search(T key) {
            if (get_index(key) != -1) return true;

            return false;
        }

        void print_hash() const {
            for (int i=0; i<dimensione; i++) {
                std::cout << table[i] << "  ";
            }

            std::cout << std::endl;
        }
};

#endif