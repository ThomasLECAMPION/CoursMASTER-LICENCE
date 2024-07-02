#include <stdio.h>
#include "cmath"
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;

  if (argc != 3)
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n");
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
 int voisin;
 for (int i=0; i < nH; i++) {
   for (int j=0; j < nW; j++)
     {
       if(i == 0 && j == 0) {
         voisin = ImgIn[i*nW+j];
       }
       else if(i == 0) {
         voisin = ImgIn[i*nW+(j-1)];
       }
       else if(j == 0) {
         voisin = ImgIn[(i-1)*nW+j];
       }
       else {
         int ab = abs(ImgIn[i*nW+(j-1)] - ImgIn[(i-1)*nW+(j-1)]);
         int bc = abs(ImgIn[(i-1)*nW+(j-1)] - ImgIn[(i-1)*nW+j]);
         if (ab < bc) {
           voisin = ImgIn[(i-1)*nW+j];
         }
         else {
           voisin = ImgIn[i*nW+(j-1)];
         }
       }

       int erreur = ImgIn[i*nW+j] - voisin + 128;
       if(erreur < 0) {
         ImgOut[i*nW+j] = 0;
       }
       else if (erreur > 255) {
         ImgOut[i*nW+j] = 255;
       }
       ImgOut[i*nW+j] = erreur;
     }
  }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
