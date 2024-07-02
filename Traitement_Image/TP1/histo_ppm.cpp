#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int histoR[256], histoG[256], histoB[256];
  int nH, nW, nTaille, nR, nG, nB;

  for (int i=0; i<256; i++) {
    histoR[i] = 0;
    histoG[i] = 0;
    histoB[i] = 0;
  }

  if (argc != 2)
     {
       printf("Usage: ImageIn.ppm \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;

   OCTET *ImgIn;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = (nH * nW);

   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nTaille);

   for (int i=0; i < nTaille*3; i+=3)
     {
       nR = ImgIn[i];
       nG = ImgIn[i+1];
       nB = ImgIn[i+2];
       histoR[(int)nR]++;
       histoG[(int)nG]++;
       histoB[(int)nB]++;
     }

     for(int i=0; i<256; i++) {
       std::cout<< i << " " << histoR[i] << " " << histoG[i] << " " << histoB[i] <<std::endl;
     }

   free(ImgIn);
   return 1;
}
