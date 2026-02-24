// Conteggio dei caratteri. Scrivere una funzione ricorsiva che, data una stringa S, restituisca il numero totale
// dei suoi caratteri. Suggerimento: ridurre la lunghezza di una stringa di un carattere a ogni passo e incrementare
// un contatore.
#include <iostream>
using namespace std;

int numero_caratteri(string parola) {
    if (parola.empty()) {
        return 0;
    }

    return 1 + numero_caratteri(parola.substr(1));
}

// alternativa più efficiente non calcola substring O(n)
/*
i = indice del carattere attuale
int numero_caratteri(string parola, int i) {
    if (i == parola.length()) 
        return 0;

    return 1 + numero_caratteri(parola, i+1);
}
*/

int main(void) {
    string ciao = "ciao";

    cout << "La stringa è lunga " << numero_caratteri(ciao) << " carattereri\n\n";
}