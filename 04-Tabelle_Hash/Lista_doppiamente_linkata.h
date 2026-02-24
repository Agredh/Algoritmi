#ifndef LISTA_DOPPIAMENTE_LINKATA_H
#define LISTA_DOPPIAMENTE_LINKATA_H
#include <iostream>
#include <climits>
#include "Nodo.h"

template<class H> class Lista {
    private: 
        int numero_elementi;
        Nodo<H> *header;
        Nodo<H> *trailer;

        void print_ricorsiva(Nodo<H> *tmp) const {
            if (tmp == trailer) return; 

            std::cout << tmp->get_key() << "   ";
            print_ricorsiva(tmp->get_next());
        }



    public:
        Lista() {
            this->numero_elementi = 0;
            header = new Nodo<H>(H());
            trailer = new Nodo<H>(H(), header);
            header->set_next(trailer);
        }

        Lista<H> *inserisci(H key) {
            Nodo<H> *successivo = header->get_next();
            Nodo<H> *nodo = new Nodo<H>(key, header, successivo);
            header->set_next(nodo);
            successivo->set_prev(nodo);
            numero_elementi++;

            return this;
        }

        Lista<H> *cancella(H key) {
            Nodo<H> *canc = get_nodo(key);

            if (get_nodo(key) != nullptr) {
                canc->get_prev()->set_next(canc->get_next());
                canc->get_next()->set_prev(canc->get_prev());
                delete canc;
                numero_elementi--;
            }

            return this;
        }

        Lista<H> *cancella_nodo(Nodo<H> *nodo) {
            if (nodo != nullptr) {
                nodo->get_prev()->set_next(nodo->get_next());
                nodo->get_next()->set_prev(nodo->get_prev());
                delete nodo;
                numero_elementi--;
            }

            return this;
        }

        bool ricerca(H key) {
            Nodo<H> *nodo = get_nodo(key);

            if (nodo != nullptr) {
                return true;
            }

            return false;
        }

        bool vuota() {
            if (numero_elementi == 0) {
                return true;
            }

            return false;
        }

        Nodo<H> *get_nodo(H key) const {
            Nodo<H> *attuale = header->get_next();

            while (attuale!=trailer && attuale->get_key()!=key) {
                attuale = attuale->get_next();
            }

            if (attuale!=trailer && attuale->get_key()==key) {
                return attuale;
            }

            return nullptr;
        }

        void print() const {
            print_ricorsiva(header->get_next());
            std::cout << std::endl;
        }
};

#endif