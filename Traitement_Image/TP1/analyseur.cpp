#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille, ligne, indice;

  if (argc != 4)
     {
       printf("Usage: ImageIn.pgm Ligne Indice \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%d",&ligne);
   sscanf (argv[3],"%d",&indice);

   OCTET *ImgIn;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   if(ligne == 0) {
     for (int j=0; j < nW; j++)
       {
         std::cout<< indice*nW+j << " " << (int)ImgIn[indice*nW+j] <<std::endl;
       }
   }
   else {
     for (int i=0; i < nW; i++)
       {
         std::cout<< i*nW+indice << " " << (int)ImgIn[i*nW+indice] <<std::endl;
       }
   }

   free(ImgIn);
   return 1;
}
