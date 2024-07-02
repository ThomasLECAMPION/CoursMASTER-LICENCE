#ifndef EVALPERF_H
#define EVALPERF_H
#include <iostream>
#include <chrono>
#include <x86intrin.h>

class EvalPerf
{
    public:
        EvalPerf();
        std::chrono::time_point<std::chrono::high_resolution_clock> debut_temps, fin_temps;
        int debut_cycle, fin_cycle;
        uint64_t rdtsc();
        void start();
        void stop();
        int nb_cycle();
        int microsecond();
        float cpi(int n);
};
#endif
