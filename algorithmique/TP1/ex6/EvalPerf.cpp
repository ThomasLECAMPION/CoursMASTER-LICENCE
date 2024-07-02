#include "EvalPerf.h"
#include <iostream>
#include <chrono>
#include <x86intrin.h>

EvalPerf::EvalPerf()
{}

uint64_t EvalPerf::rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

void EvalPerf::start() {
    this->debut_temps = std::chrono::high_resolution_clock::now();
    this->debut_cycle = rdtsc();
}

void EvalPerf::stop() {
    this->fin_cycle = rdtsc();
    this->fin_temps = std::chrono::high_resolution_clock::now();
}

int EvalPerf::nb_cycle() {
    return (fin_cycle - debut_cycle);
}

int EvalPerf::microsecond() {
    return (fin_temps - debut_temps).count();
}

float EvalPerf::cpi(int n) {
    return nb_cycle()/n;
}
