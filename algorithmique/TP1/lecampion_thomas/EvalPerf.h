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
        uint64_t debut_cycle, fin_cycle;
        uint64_t rdtsc();
        void start();
        void stop();
        uint64_t nb_cycle();
        uint64_t microsecond();
        float cpi(int n);
};
#endif
