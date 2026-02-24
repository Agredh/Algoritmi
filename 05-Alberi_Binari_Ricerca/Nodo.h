#ifndef NODO2_H
#define NODO2_H

template<class T> class Nodo {
    private:
        T key;
        Nodo<T> *parent;
        Nodo<T> *left;
        Nodo<T> *right;

    public:
        Nodo(T key) : key(key) {
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }

        Nodo(T key, Nodo<T> *parent, Nodo<T> *left, Nodo<T> *right) {
            set_key(key);
            set_parent(parent);
            set_left(left);
            set_right(right);
        }

        // metodi setter
        void set_key(T key) { this->key = key; }
        void set_parent(Nodo<T> *parent) { this->parent = parent; }
        void set_left(Nodo<T> *left) { this->left = left; }
        void set_right(Nodo<T> *right) { this->right = right; }

        // metodi getter
        T get_key() const { return key; }
        Nodo<T> *get_parent() const { return parent; }
        Nodo<T> *get_left() const { return left; }
        Nodo<T> *get_right() const { return right; }
};

#endif