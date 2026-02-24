#ifndef ALBERO_BINARIO_H
#define ALBERO_BINARIO_H

#include <iostream>
#include "Nodo.h"

template<class H> class Albero_binario {
    private:
        Nodo<H> *root;

        void pre_order(Nodo<H> *nodo) const {
            if (nodo != nullptr) {
                std::cout << nodo->get_key() << "  ";
                pre_order(nodo->get_left());
                pre_order(nodo->get_right());
            }
        }

        void post_order(Nodo<H> *nodo) const {
            if (nodo != nullptr) {
                post_order(nodo->get_left());
                post_order(nodo->get_right());
                std::cout << nodo->get_key() << "  ";
            }
        }

        void in_order(Nodo<H> *nodo) const {
            if (nodo != nullptr) {
                in_order(nodo->get_left());
                std::cout << nodo->get_key() << "  ";
                in_order(nodo->get_right());
            }
        }

        Nodo<H> *_search(Nodo<H> *x, H key) const {
            if (x==nullptr || x->get_key()==key) {
                return x;
            }

            if (key < x->get_key()) {
                return _search(x->get_left(), key);
            }
            
            return _search(x->get_right(), key);
        }

        Nodo<H> *get_minimum(Nodo<H> *x) const {
            while (x->get_left() != nullptr) {
                x = x->get_left();
            }

            return x;
        }

        Nodo<H> *get_maximum(Nodo<H> *x) const {
            while (x->get_right()!=nullptr) {
                x = x->get_right();
            }

            return x;
        }

        Nodo<H> *tree_successor(Nodo<H> *x) const {
            if (x->get_right() != nullptr) {
                return get_minimum(x->get_right());
            }

            Nodo<H> *y = x->get_parent();
            
            while (y!=nullptr && y->get_right()==x) {
                x = y;
                y = y->get_parent();
            }

            return y;
        }

        void transplant(Nodo<H> *u, Nodo<H> *v) {
            if (u->get_parent() == nullptr) {
                root = v;
            }
            else if (u == u->get_parent()->get_left()) {
                u->get_parent()->set_left(v);
            }
            else {
                u->get_parent()->set_right(v);
            }

            if (v != nullptr) {
                v->set_parent(u->get_parent());
            }
        }

    public:
        Albero_binario() {
            root = nullptr;
        }

        void pre_order() const { 
            pre_order(root);
            std::cout << std::endl;
        }

        void post_order() const { 
            post_order(root); 
            std::cout << std::endl;
        }

        void in_order() const { 
            in_order(root); 
            std::cout << std::endl;
        }

        Albero_binario<H> *insert(H key) {
            Nodo<H> *z = new Nodo<H>(key);
            Nodo<H> *y = nullptr;
            Nodo<H> *x = root;

            while (x!=nullptr) {
                y = x;

                if (z->get_key()<x->get_key()) {
                    x = x->get_left();
                }
                else {
                    x = x->get_right();
                }
            }

            z->set_parent(y);

            if (y == nullptr) {
                root = z;
            }
            else if (z->get_key() < y->get_key()){
                y->set_left(z);
            }
            else {
                y->set_right(z);
            }

            return this;
        }

        bool search(H key) const {
            return (_search(root, key) != nullptr) ? true : false;
        }

        H tree_min() const {
            return get_minimum(root)->get_key();
        }

        H tree_max() const {
            return get_maximum(root)->get_key();
        }

        H successor(H key) {
            Nodo<H> *nodo = _search(root, key);
            if (nodo != nullptr) {
                nodo = tree_successor(nodo);
            }

            if (nodo != nullptr) {
                return nodo->get_key();
            }

            return -1;
        }

        Albero_binario<H> *delete_node(H key) {
            Nodo<H> *z = _search(root, key);

            if (z != nullptr) {

                if (z->get_left() == nullptr) {
                    transplant(z, z->get_right());
                }
                else if (z->get_right() == nullptr) {
                    transplant(z, z->get_left());
                }
                else {
                    Nodo<H> *y = get_minimum(z->get_right());

                    if (y->get_parent() != z) {
                        transplant(y, y->get_right());
                        y->set_right(z->get_right());
                        y->get_right()->set_parent(y);
                    }

                    transplant(z, y);
                    y->set_left(z->get_left());
                    y->get_left()->set_parent(y);
                }
            }

            return this;
        }
};

#endif