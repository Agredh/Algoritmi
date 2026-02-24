#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

template <class H> class Elemento {
    private: 
        int key;
        H data;

    public:
        Elemento(int key, H data) {
            set_elemento(key, data);
        }

        void set_elemento(int key, H data) {
            set_key(key);
            set_data(data);
        }

        void set_key(int key) {
            this->key = key;
        }

        void set_data(H data) {
            this->data = data;
        }

        int get_key() const {
            return key;
        }

        H get_data() const {
            return data;
        }

        void print_elemento() const {
            std::cout << "Chiave: " << key << ", Data: " << data << ".\n";
        }
};

#endif