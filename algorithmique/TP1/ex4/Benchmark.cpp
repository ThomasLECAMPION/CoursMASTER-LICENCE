#include <iostream>
#include <chrono>
#include "EvalPerf.h"
#include "SommePrefixe.h"

int main() {
    EvalPerf PE;

    int n = 100000;
    int nb_cycle = 0;
    int nb_microsecond = 0;
    float nb_CPI = 0;

    for(int i=0; i<n; i++){
        PE.start();
        maFonction();
        PE.stop();

        nb_cycle += PE.nb_cycle();
        nb_microsecond += PE.microsecond();
        nb_CPI += PE.cpi(8+12+6);
    }

    std::cout<<"nbr cycle moyen: "<<nb_cycle/n<<std::endl;
    std::cout<<"nbr microsecondes moyen: "<<nb_microsecond/n<<"µs"<<std::endl;
    std::cout<<"CPI moyen: "<<nb_CPI/n<<std::endl;
    return 0;
}
