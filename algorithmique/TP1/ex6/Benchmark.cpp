#include <iostream>
#include <chrono>
#include <vector>
#include "EvalPerf.h"
#include "maFonction.h"

int main(int argc, char *argv[]) {
    EvalPerf PE;

    int n = 100000;
    int nb_cycle = 0;
    int nb_microsecond = 0;
    float nb_CPI = 0;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(2);

    for(int i=0; i<n; i++){
        PE.start();

        int res;
        maFonction4(vec, res);

        PE.stop();

        nb_cycle += PE.nb_cycle();
        nb_microsecond += PE.microsecond();
        nb_CPI += PE.cpi(60);
    }

    std::cout<<"nbr cycle moyen: "<<nb_cycle/n<<std::endl;
    std::cout<<"nbr microsecondes moyen: "<<nb_microsecond/n<<"µs"<<std::endl;
    std::cout<<"CPI moyen: "<<nb_CPI/n<<std::endl;
    return 0;
}
