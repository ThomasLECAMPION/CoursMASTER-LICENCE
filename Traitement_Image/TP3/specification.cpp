#include <iostream>
#include <stdio.h>
#include <math.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgLue2[250], cNomImgEcrite[250];
  int histoR[256], histoB[256];
  float ddpR[256], fR[256], ddpB[256], fB[256], fiR[256];
  int nH, nW, nTaille;

  for (int i=0; i<256; i++) {
    histoR[i] = 0; histoB[i] = 0;
  }

  if (argc != 4)
     {
       printf("Usage: ImageR.pgm ImageB.pgm ImageOut.pgm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgLue2) ;
   sscanf (argv[3],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgIn2, *ImgOut;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   allocation_tableau(ImgIn2, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   lire_image_pgm(cNomImgLue2, ImgIn2, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         histoR[(int)ImgIn[i*nW+j]]++;
       }
   }
   for(int i=0; i<256; i++) {
     ddpR[i] = (float)histoR[i] / (float)nTaille;
   }
   fR[0] = ddpR[0];
   fiR[0] = ddpR[255];
   for(int i=1; i<256; i++) {
     fR[i] = fR[i-1] + ddpR[i];
     fiR[i] = 1/fR[i];
   }

   for( int i=0; i < nH; i++)
   {
     for (int j=0; j < nW; j++)
       {
         ImgOut[i*nW+j] = ceil(255 * fR[ImgIn[i*nW+j]]);
         ImgOut[i*nW+j] = ceil(255 * fiR[ImgOut[i*nW+j]]);
       }
   }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
