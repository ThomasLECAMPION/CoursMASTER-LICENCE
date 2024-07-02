#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "EvalPerf.h"
#include "maFonction.h"

int main(int argc, char *argv[]) {
    EvalPerf PE;

    int n = 1000;
    uint64_t nb_cycle = 0;
    uint64_t nb_microsecond = 0;
    float nb_CPI = 0;

    //Exercice 21
    srand (time(NULL));
    size_t n_tab = (int)pow(2,16);
    size_t T[n_tab];
    size_t min = n_tab+1;
    size_t max = -1;
    for(size_t i=0; i<n_tab; i++) {
      T[i] = rand() % n_tab + 0;
      if (T[i] < min) min = T[i];
      if (T[i] > max) max = T[i];
    }
    size_t R[n_tab];

    for(int i=0; i<n; i++){
        PE.start();

        counting_sort_bucket(R, T, n_tab, min, max);

        PE.stop();

        nb_cycle += PE.nb_cycle();
        nb_microsecond += PE.microsecond();
        nb_CPI += PE.cpi(1);
    }

    std::cout<<"nbr cycle moyen: "<<nb_cycle/n<<std::endl;
    std::cout<<"nbr microsecondes moyen: "<<nb_microsecond/n<<"µs"<<std::endl;
    std::cout<<"CPI moyen: "<<nb_CPI/n<<std::endl;

    return 0;
}
