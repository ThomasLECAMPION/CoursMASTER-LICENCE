#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int histo[256];
  int nH, nW, nTaille;

  for (int i=0; i<256; i++) {
    histo[i] = 0;
  }

  if (argc != 3)
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);

   int a0 = 255; int a1 = 0;

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         histo[(int)ImgIn[i*nW+j]]++;
         if(ImgIn[i*nW+j] < a0) a0 = ImgIn[i*nW+j];
         if(ImgIn[i*nW+j] > a1) a1 = ImgIn[i*nW+j];
       }
   }

   float alpha = 255*(a0/(a1-a0));
   float beta = 255/(a1-a0);

   std::cout<<"a0="<<a0<<" et a1="<<a1<<std::endl;
   std::cout<<"alpha="<<alpha<<" et beta="<<beta<<std::endl;

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         ImgOut[i*nW+j] = alpha + beta*ImgIn[i*nW+j];
       }
   }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
