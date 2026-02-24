#include <iostream>
#include "Albero_Binario.h"
using namespace std;

int main(void) {
    Albero_binario<int> *bst = new Albero_binario<int>();
    bst->insert(7)->insert(9)->insert(5)->insert(12)->insert(2)->insert(3);
    bst->in_order();
    bst->pre_order();
    bst->post_order();
    
    int ricerca = 12;
    if (bst->search(ricerca)) {
        cout << ricerca << " è presente nell'albero\n";
    } else {
        cout << ricerca << " non è presente nell'albero\n";
    }

    ricerca = 120;
    if (bst->search(ricerca)) {
        cout << ricerca << " è presente nell'albero\n";
    } else {
        cout << ricerca << " non è presente nell'albero\n";
    }

    cout << "Minimo: " << bst->tree_min() << endl;
    cout << "Massimo: " << bst->tree_max() << endl;

    int successore = bst->successor(12);
    if (successore != -1) {
        cout << "Il successore di 12 è " << successore << endl;
    }
    else {
        cout << "12 non ha successori.\n";
    }

    successore = bst->successor(2);
    if (successore != -1) {
        cout << "Il successore di 2 è " << successore << endl;
    }
    else {
        cout << "2 non ha successori.\n";
    }

    successore = bst->successor(3);
    if (successore != -1) {
        cout << "Il successore di 3 è " << successore << endl;
    }
    else {
        cout << "3 non ha successori.\n";
    }

    bst->in_order();
    bst->post_order();
    bst->pre_order();
    bst->delete_node(5);
    bst->in_order();
    bst->post_order();
    bst->pre_order();
}