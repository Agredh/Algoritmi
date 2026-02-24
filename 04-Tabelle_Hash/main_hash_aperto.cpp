#include <iostream>
#include "Hash_Aperto.h"
using namespace std;

int main(void) {
    Hash_Aperto<int> *hash = new Hash_Aperto<int>(4);
    hash->hash_insert(1)->hash_insert(2)->hash_insert(3)->hash_insert(4)->hash_insert(5)->hash_insert(6);
    hash->print_hash();
}