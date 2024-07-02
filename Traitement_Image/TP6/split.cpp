#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

void split(int x, int y, int largeur, int taille, int seuil, OCTET *ImgIn, OCTET *ImgOut) {
  int moyenne[4], variance[4], i_region;
  for(int i=0; i<4; i++) {
    moyenne[i]=0;
    variance[i]=0;
  }

  for (int i=x; i < largeur; i++) {
    for(int j=y; j < largeur; j++) {
      if(i<x+(largeur/2) && j<y+(largeur/2)) {
        i_region = 0;
      }
      else if (i<x+(largeur/2) && j>=y+(largeur/2)) {
        i_region = 1;
      }
      else if (i>=x+(largeur/2) && j<y+(largeur/2)) {
        i_region = 2;
      }
      else {
        i_region = 3;
      }

      moyenne[i_region] += ImgIn[i*taille+j];
    }
  }

  for(int i=0; i<4; i++) {
    moyenne[i] /= (largeur*largeur)/4;
  }

  for (int i=x; i < largeur; i++) {
    for(int j=y; j < largeur; j++) {
      if(i<x+(largeur/2) && j<y+(largeur/2)) {
        i_region = 0;
      }
      else if (i<x+(largeur/2) && j>=y+(largeur/2)) {
        i_region = 1;
      }
      else if (i>=x+(largeur/2) && j<y+(largeur/2)) {
        i_region = 2;
      }
      else {
        i_region = 3;
      }
      variance[i_region] += (ImgIn[i*taille+j]-moyenne[i_region]) * (ImgIn[i*taille+j]-moyenne[i_region]);
      ImgOut[i*taille+j] = moyenne[i_region];
    }
  }

  int c = 0;
  for(int i=0; i<4; i++) {
    variance[i] /= (largeur*largeur)/4;
    int new_x, new_y;
    if((largeur>=8) && (variance[i] > seuil)) {
      if(i==0) {
        new_x = x;
        new_y = y;
      }
      else if(i==1) {
        new_x = x + largeur/2;
        new_y = y;
      }
      else if(i==2) {
        new_x = x;
        new_y = y + largeur/2;
      }
      else {
        new_x = x + largeur/2;
        new_y = y + largeur/2;
      }
      split(new_x, new_y, largeur/2, taille, seuil, ImgIn, ImgOut);
    }
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

   split(0, 0, nH, nH, 1, ImgIn, ImgOut);

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
