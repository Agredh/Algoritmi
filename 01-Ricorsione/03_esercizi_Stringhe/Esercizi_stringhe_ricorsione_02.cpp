// Conteggio di una lettere specifica. Scrivere una funzione ricorsiva che conte quante volte un carattere c
// compare all'interno di una stringa S. Suggerimento: confrontare il primo carattere di S con c e proseguire 
// resto della stringa.
#include <iostream>
using namespace std;

int numero_occorrenze(string parola, char carattere) {
    if (parola.empty()) {
        return 0;
    }

    return ((parola[0] == carattere) ? 1 : 0) + numero_occorrenze(parola.substr(1), carattere);
}

/*
Alternativa più perfomante non utilizzando il metodo di classe substr()
int numero_occorrenze(string parola, char carattere, int i) {
    if (i == parola.length())
        return 0;

    return ((parola[0] == carattere) ? 1 : 0) + numero_occorrenze(parola, carettere, i+1);
}
*/

int main(void) {
    string ciao = "ciaociaociaociao";

    cout << "Numero occorenze c: " << numero_occorrenze(ciao, 'r') << endl;
}