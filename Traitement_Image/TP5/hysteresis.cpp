#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;

  if (argc != 3)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue);
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut;
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);

   int horizontal, vertical, gradient;
   int sH, sB;
   bool contours[nTaille];
   for (int i=0; i < nTaille; i++) {
      contours[i] = false;
   }
   sH = 70;
   sB = 20;
   for (int i=0; i < nH; i++)
     {
       for(int j=0; j < nW; j++)
       {
         if(ImgIn[i*nW+j] > sH) {
           contours[i*nW+j] = true;
           ImgOut[i*nW+j] = 255;
         }
       }
     }

   for (int i=0; i < nH; i++)
     {
       for(int j=0; j < nW; j++)
       {
         if((ImgIn[i*nW+j] >= sB) || (ImgIn[i*nW+j] <= sH)) {
           if(contours[(i-1)*nW+j] || contours[(i+1)*nW+j] || contours[i*nW+(j-1)] || contours[i*nW+(j+1)]) {
             ImgOut[i*nW+j] = 255;
           }
         }
       }
     }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
