#include <iostream>
#include "Hash_concatenata.h"
using namespace std;

int main(void) {
    Hash_Concatenata<int> *tabella = new Hash_Concatenata<int>();
    tabella->insert(5)->insert(1)->insert(2)->insert(3)->insert(4)->insert(6)->insert(7)->insert(8)->insert(9)->insert(10)->insert(11)->insert(12)->insert(13)->insert(14)->insert(15)->insert(16);
    tabella->print_hash();
    tabella->delete_key(14)->delete_key(1)->delete_key(120);
    tabella->print_hash();

    if (tabella->search(120)) {
        cout << "La chiave 120 è presente nella tabella\n";
    } else {
        cout << "La chiave 120 non è presente nella tabella\n";
    }

    if (tabella->search(10)) {
        cout << "La chiave 10 è presente nella tabella\n";
    } else {
        cout << "La chiave 10 non è presente nella tabella\n";
    }
}