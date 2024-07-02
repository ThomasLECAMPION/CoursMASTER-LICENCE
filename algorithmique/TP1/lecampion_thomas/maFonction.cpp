#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "maFonction.h"

void matrixTrans_naif() {
  int taille_mat = 4;
  double matrice[taille_mat][taille_mat] = {{0,1,2,3},
                                         {4,5,6,7},
                                         {8,9,10,11},
                                         {12,13,14,15}};
  int new_matrice[taille_mat][taille_mat];

  for(int i=0; i<taille_mat; i++) {
    for(int j=0; j<taille_mat; j++) {
      new_matrice[i][j] = matrice[j][i];
    }
  }

  /*
  for(int i=0; i<taille_mat; i++) {
   std::cout<<std::endl;
   for(int j=0; j<taille_mat; j++) {
     std::cout<<new_matrice[i][j]<<" ";
   }
  }
  std::cout<<std::endl;
  */
}

void matrixTrans_bloc() {
  int taille_bloc = 2;
  int taille_mat = 4;
  double matrice[taille_mat][taille_mat] = {{0,1,2,3},
                                         {4,5,6,7},
                                         {8,9,10,11},
                                         {12,13,14,15}};

  int new_matrice[taille_mat][taille_mat];

  for(int i=0; i<taille_mat; i+=taille_bloc) {
    for(int j=0; j<taille_mat; j+=taille_bloc) {
      for(int a=0; a<taille_bloc; a++) {
        for(int b=0; b<taille_bloc; b++) {
          new_matrice[i+a][j+b] = matrice[j+b][i+a];
        }
      }
    }
  }

  /*
  for(int i=0; i<taille_mat; i++) {
    std::cout<<std::endl;
    for(int j=0; j<taille_mat; j++) {
      std::cout<<new_matrice[i][j]<<" ";
    }
  }
  std::cout<<std::endl;
  */
}

void matrixTrans_obliv(size_t m, size_t n, const double* A, size_t sa, double * B, size_t
sb) {

}

void counting_sort_naif(size_t* R, const size_t *T, size_t n, size_t min, size_t max) {
    size_t counting[n];
    for(size_t i=0; i<n; i++) {
      counting[i] = 0;
    }
    for(size_t i=0; i<n; i++) {
      counting[T[i]]++;
    }

    size_t index = 0;
    for(size_t i=0; i<n; i++) {
      for(size_t j=0; j<counting[i]; j++) {
        R[index] = i;
        index++;
      }
    }

    /*
    for(size_t i=0; i<n; i++) {
      std::cout<<R[i]<<" ";
    }
    std::cout<<std::endl;
    */
}

void counting_sort_bucket(size_t* R, const size_t *T, size_t n, size_t min, size_t max) {
    size_t m = 64;
    if(n < 128) {
      m = std::min(4, (int)n);
    }
    size_t size_bucket = n/m;
    size_t buckets[m][size_bucket];

    size_t index_bucket[m];
    for(size_t i=0; i<m; i++) {
      index_bucket[i] = 0;
    }

    for(size_t i=0; i<n; i++) {
      size_t bucket = floor(T[i]/size_bucket);
      if(index_bucket[bucket] >= size_bucket) { //le bucket est full, on se met à ranger n'importe comment
        bucket = 0;
        while(true) {
          if(index_bucket[bucket] < size_bucket) {
            break;
          }
          bucket++;
        }
      }
      buckets[bucket][index_bucket[bucket]] = T[i];
      index_bucket[bucket]++;
    }

    size_t counting[n];
    for(size_t i=0; i<n; i++) {
      counting[i] = 0;
    }
    for(size_t i=0; i<m; i++) {
      for(size_t j=0; j<size_bucket; j++)
      counting[buckets[i][j]]++;
    }

    size_t index = 0;
    for(size_t i=0; i<n; i++) {
      for(size_t j=0; j<counting[i]; j++) {
        R[index] = i;
        index++;
      }
    }

    /*
    for(size_t i=0; i<n; i++) {
      std::cout<<R[i]<<" ";
    }
    std::cout<<std::endl;
    */
}
