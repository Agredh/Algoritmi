#include <iostream>
#include "Elemento.h"
#include "Hash_Indirizzamento_diretto.h"
using namespace std;

int main(void) {
    Elemento<string> *e1 = new Elemento<string>(1, "Agostino");
    Elemento<string> *e2 = new Elemento<string>(2, "Simone");
    Elemento<string> *e3 = new Elemento<string>(3, "Francesco");
    Elemento<string> *e4 = new Elemento<string>(4, "Filippo");
    Elemento<string> *e5 = new Elemento<string>(5, "Gabriele");

    Hash_Diretto<string> *tabella = new Hash_Diretto<string>(5);
    tabella->insert(e1);
    tabella->insert(e2);
    tabella->insert(e3);
    tabella->insert(e4);
    tabella->insert(e5);
    tabella->print();

    Elemento<string> *s = tabella->search(3);
    cout << endl;
    s->print_elemento();
    cout << endl;
    tabella->print();
    delete s;

    tabella->delete_element(3);
    cout << endl;
    tabella->print();
    cout << endl;

    tabella->delete_element(2);
    tabella->delete_element(1);
    tabella->print();
    cout << endl;

    tabella->delete_element(4);
    tabella->delete_element(3);
    tabella->print();

    delete e1, e2, e3, e4, e5;
}