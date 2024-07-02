#include <iostream>
#include "SommePrefixe.h"

void maFonction(){
    int tab[4] = {1,3,10,3};
    for(int i=1; i<4; i++) {
        tab[i] += tab[i-1];
    }
}
