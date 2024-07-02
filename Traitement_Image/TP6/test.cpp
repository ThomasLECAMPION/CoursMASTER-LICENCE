#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

void split(int region, int taille, OCTET *ImgIn, OCTET *ImgOut) {
  int moyenne[4], variance[4];
  for(int i=0; i<4; i++) {
    moyenne[i]=0;
    variance[i]=0;
  }

  for(int i=0; i<taille; i++) {
    for(int j=0; j<taille; j++) {
      if(i<(taille/2) && j<(taille/2)) {
        ImgOut[i*taille+j] = region;
      }
      else if (i<(taille/2) && j>=(taille/2)) {
        ImgOut[i*taille+j] = region + 1;
      }
      else if (i>=(taille/2) && j<(taille/2)) {
        ImgOut[i*taille+j] = region + 2;
      }
      else {
        ImgOut[i*taille+j] = region + 3;
      }
    }
  }
  if(taille >= 8) {
    split(region+4, taille/2, ImgIn, ImgOut);
  }
}

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

   split(0, nH, ImgIn, ImgOut);

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
