#include <iostream>
#include <vector>
#include "maFonction.h"

//fonction de base
#define OP *
#define START 1
void maFonction(const std::vector<int> &V, int &res) {
    res = START;
    for(size_t i=0; i<V.size(); i++) {
        res = res OP V[i];
    }
}
//reduce 2 -> sans appel de fonction size()
void maFonction2(const std::vector<int> &V, int &res) {
    res = START;
    for(size_t i=0; i<V.size(); i++) {
        res = res OP V[i];
    }
}
//reduce 3 -> resultat dans tmp
void maFonction3(const std::vector<int> &V, int &res) {
    res = START;
    int tmp;
    for(size_t i=0; i<V.size(); i++) {
        tmp = res OP V[i];
        res = tmp;
    }
}
//reduce 4 -> deroulage de boucle
void maFonction4(const std::vector<int> &V, int &res) {
    res = START;
    int res2 = res;
    for(size_t i=0; i<V.size(); i+=2) {
        res = res OP V[i];
        res2 = res OP V[i+1];
    }
}
//reduce 5 -> deroulage de boucle avec 2 accumulateurs
void maFonction5(const std::vector<int> &V, int &res) {
    res = START;
    for(size_t i=0; i<V.size(); i++) {
        res = res OP V[i];
    }
}
