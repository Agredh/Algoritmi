#include <iostream>
#include "Lista_doppiamente_linkata.h"
using namespace std;

int main(void) {
    Lista<int> *lista = new Lista<int>();

    lista->inserisci(5)->inserisci(10)->inserisci(15);
    lista->print();
    lista->cancella(10)->cancella(15)->cancella(5)->print();
    lista->inserisci(12)->inserisci(13)->inserisci(22);
    lista->print();

    if (lista->ricerca(22)) {
        cout << "L'elemento 22 è presente nella lista\n";
    }
    else {
        cout << "L'elemento 22 non è presente nella lista\n";
    }

    if (lista->ricerca(23)) {
        cout << "L'elemento 23 è presente nella lista\n";
    }
    else {
        cout << "L'elemento 23 non è presente nella lista\n";
    }

    Nodo<int> *nodo = lista->get_nodo(22);
    lista->cancella_nodo(nodo);
    lista->print();

}