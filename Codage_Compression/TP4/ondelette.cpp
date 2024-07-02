#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cBF[250], cMFV[250], cMFH[250], cHF[250];
  int nH, nW, nTaille;

  if (argc != 6)
     {
       printf("Usage: ImageIn.pgm BF.pgm MFV.pgm MFH.pgm HF.pgm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cBF);
   sscanf (argv[3],"%s",cMFV);
   sscanf (argv[4],"%s",cMFH);
   sscanf (argv[5],"%s",cHF);

   OCTET *ImgIn, *bf, *mfv, *mfh, *hf;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   allocation_tableau(bf, OCTET, nTaille/2);
   allocation_tableau(mfv, OCTET, nTaille/2);
   allocation_tableau(mfh, OCTET, nTaille/2);
   allocation_tableau(hf, OCTET, nTaille/2);

   int a, b, c, d;
   float fpb0, fpb1, fph0, fph1;

   int q = 64;
   int q2 = q/2;

   for( int i=0; i < nH; i+=2)
   {
     for (int j=0; j < nW; j+=2)
       {
         a = ImgIn[i*nW+j];
         b = ImgIn[i*nW+(j+1)];
         c = ImgIn[(i+1)*nW+j];
         d = ImgIn[(i+1)*nW+(j+1)];

         fpb0 = (a+b)/2;
         fpb1 = (c+d)/2;
         fph0 = a-b;
         fph1 = c-d;

         bf[(i/2)*(nW/2)+(j/2)] = round((fpb0+fpb1)/2);
         mfv[(i/2)*(nW/2)+(j/2)] = (round((fpb0-fpb1)/q2) * q2) + 128;
         mfh[(i/2)*(nW/2)+(j/2)] = (round(((fph0+fph1)/2)/q2) * q2) + 128;
         hf[(i/2)*(nW/2)+(j/2)] = (round((fph0-fph1)/q) * q) + 128;
       }
   }

   ecrire_image_pgm(cBF, bf,  nH/2, nW/2);
   ecrire_image_pgm(cMFV, mfv,  nH/2, nW/2);
   ecrire_image_pgm(cMFH, mfh,  nH/2, nW/2);
   ecrire_image_ppm(cHF, hf,  nH/2, nW/2);
   free(ImgIn);
   return 1;
}
