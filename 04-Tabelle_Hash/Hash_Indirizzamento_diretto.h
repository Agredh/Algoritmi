#include <iostream>
#include "Elemento.h"

template<class T> class Hash_Diretto {
    private:
        Elemento<T> **tabella;
        int dimensione;
        int numero_elementi;

    public:
        Hash_Diretto(int dimensione) {
            this->dimensione = dimensione;
            this->numero_elementi = 0;

            tabella = new Elemento<T>*[dimensione];
        }

        Elemento<T> *search(int key) const {
            return tabella[key];
        }

        void delete_element(int key) {
            tabella[key] = NULL;
        }

        void insert(Elemento<T> *e) {
            if (numero_elementi < dimensione && e->get_key()>=0 && e->get_key()<dimensione) {
                tabella[e->get_key()] = e;
                numero_elementi++;
            }
        }

        void print() const {
            for (int i=0; i<dimensione; i++) {
                if (tabella[i] != nullptr)
                    tabella[i]->print_elemento();
            }
        }
};