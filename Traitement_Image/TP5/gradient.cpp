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

   for (int i=0; i < nH; i++)
     {
       for(int j=0; j < nW; j++)
       {
         ImgOut[i*nW+j] = 0;
         if(i!=nH && j!=nW) {
           horizontal = ImgIn[(i+1)*nW+j] - ImgIn[i*nW+j];
           vertical = ImgIn[i*nW+(j+1)] - ImgIn[i*nW+j];
           //norme du gradient
           gradient = sqrt(horizontal*horizontal + vertical*vertical);
           if(gradient > 255) {
             ImgOut[i*nW+j] = 255;
           }
           else {
             ImgOut[i*nW+j] = gradient;
           }
           //profil de la ligne 60
           if(i == 60) {
             std::cout<<j<<" "<<(int)ImgOut[i*nW+j]<<std::endl;
           }
         }
       }
     }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
