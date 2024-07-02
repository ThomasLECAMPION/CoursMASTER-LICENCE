#include <iostream>
#include <stdio.h>
#include <math.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int histo[256], histo2[256];
  float ddp[256], f[256];
  int nH, nW, nTaille;

  for (int i=0; i<256; i++) {
    histo[i] = 0; histo2[i] = 0;
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

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         histo[(int)ImgIn[i*nW+j]]++;
       }
   }
   for(int i=0; i<256; i++) {
     ddp[i] = (float)histo[i] / (float)nTaille;
   }
   f[0] = ddp[0];
   for(int i=1; i<256; i++) {
     f[i] = f[i-1] + ddp[i];
   }

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         ImgOut[i*nW+j] = ceil(255 * f[ImgIn[i*nW+j]]);
         histo2[(int)ImgOut[i*nW+j]]++;
       }
   }
   for(int i=0; i<256; i++) {
     std::cout<< i << " " << histo2[i] <<std::endl;
   }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
