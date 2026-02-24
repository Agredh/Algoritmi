#ifndef NODO_H
#define NODO_H

#include <iostream>

template <class T> class Nodo {
    private:
        T key;
        Nodo<T> *next;
        Nodo<T> *prev;

    public:
        // Costruttore
        Nodo(T key, Nodo<T> *prev=nullptr, Nodo<T> *next=nullptr) {
            set_key(key);
            set_prev(prev);
            set_next(next);
        }

        // metodi setter
        void set_key(T key) { this->key = key; }
        void set_prev(Nodo<T> *prev) { this->prev = prev; }
        void set_next(Nodo<T> *next) { this->next = next; }

        // metodi getter
        T get_key() const { return key; }
        Nodo<T> *get_prev() const {return prev; }
        Nodo<T> *get_next() const {return next; }
};

#endif