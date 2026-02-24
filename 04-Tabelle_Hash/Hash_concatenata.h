#ifndef HASH_CONCATENATA_H
#define HASH_CONCATENATA_H

#include <iostream>
#include <cmath>
#include <functional>
#include "Lista_doppiamente_linkata.h"

template <class T> class Hash_Concatenata {
    private:
        int dimensione;
        Lista<T> **table;

        int hashing_divisione(T key) {
            int h = std::hash<T>{}(key) % dimensione;
            return (h < 0) ? h + dimensione : h;
        }

        int hashing_moltiplicazione(T key) {
            double A = 0.618033;
            double val = key * A;
            return floor(dimensione * (val - floor(val)));
        }

    public:
        Hash_Concatenata() {
            dimensione = 13;
            table = new Lista<T>*[dimensione];

            for (int i=0; i<dimensione; i++) {
                table[i] = new Lista<T>();
            }
        }

        Hash_Concatenata<T> *insert(T key) {
            int lista = hashing_divisione(key);
            table[lista]->inserisci(key);

            return this;
        }

        Hash_Concatenata<T> *delete_key(T key) {
            int lista = hashing_divisione(key);
            table[lista]->cancella(key);

            return this;
        }

        bool search(T key) {
            int lista = hashing_divisione(key);
            return table[lista]->ricerca(key);
        }

        void print_hash() const {
            for (int i=0; i<dimensione; i++) {
                std::cout << i << ": ";
                if (table[i]->vuota()) {
                    std::cout << "Null\n";
                } else{
                    table[i]->print();
                }
            }
            std::cout << std::endl;
        }

        ~Hash_Concatenata() {

            for (int i=0; i<dimensione; i++) {
                delete table[i];
            }

            delete[] table;
        }
};

#endif