#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int histo[256];
  int nH, nW, nTaille;

  for (int i=0; i<256; i++) {
    histo[i] = 0;
  }

  if (argc != 2)
     {
       printf("Usage: ImageIn.pgm \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;

   OCTET *ImgIn;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         histo[(int)ImgIn[i*nW+j]]++;
       }
   }

   for(int i=0; i<256; i++) {
     std::cout<< i << " " << histo[i] <<std::endl;
   }

   free(ImgIn);
   return 1;
}
