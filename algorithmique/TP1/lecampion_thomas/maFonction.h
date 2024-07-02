#ifndef MAFONCTION_H
#define MAFONCTION_H

//Exercice 20
void matrixTrans_naif();
void matrixTrans_bloc();
void matrixTrans_obliv(size_t m, size_t n, const double* A, size_t sa, double * B, size_t
sb);

//Exercice 21
void counting_sort_naif(size_t* R, const size_t *T, size_t n, size_t min, size_t max);
void counting_sort_bucket(size_t* R, const size_t *T, size_t n, size_t min, size_t max);

#endif
