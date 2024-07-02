#include <iostream>
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int histoR[256], histoG[256], histoB[256];
  int nH, nW, nTaille;

  for (int i=0; i<256; i++) {
    histoR[i] = 0;
    histoG[i] = 0;
    histoB[i] = 0;
  }

  if (argc != 3)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille*3);

   int a0R = 255; int a0G = 255; int a0B = 255;
   int a1R = 0; int a1G = 0; int a1B = 0;

   for (int i=0; i < nH*3; i+=3)
     {
       for(int j=0; j < nW*3; j+=3)
       {
         histoR[(int)ImgIn[(i*nW+j)]]++;
         histoG[(int)ImgIn[(i*nW+j)+1]]++;
         histoB[(int)ImgIn[(i*nW+j)+2]]++;
         if(ImgIn[(i*nW+j)] < a0R) a0R = ImgIn[(i*nW+j)];
         if(ImgIn[(i*nW+j)] > a1R) a1R = ImgIn[(i*nW+j)];

         if(ImgIn[(i*nW+j)+1] < a0G) a0G = ImgIn[(i*nW+j)+1];
         if(ImgIn[(i*nW+j)+1] > a1G) a1G = ImgIn[(i*nW+j)+1];

         if(ImgIn[(i*nW+j)+2] < a0B) a0B = ImgIn[(i*nW+j)+2];
         if(ImgIn[(i*nW+j)+2] > a1B) a1B = ImgIn[(i*nW+j)+2];
       }
     }

   float alphaR = 255*(a0R/(a1R-a0R));
   float betaR = 255/(a1R-a0R);

   float alphaG = 255*(a0G/(a1G-a0G));
   float betaG = 255/(a1G-a0G);

   float alphaB = 255*(a0B/(a1B-a0B));
   float betaB = 255/(a1B-a0B);

   std::cout<<"alphaR="<<alphaR<<" et betaR="<<betaR<<std::endl;
   std::cout<<"alphaG="<<alphaG<<" et betaG="<<betaG<<std::endl;
   std::cout<<"alphaB="<<alphaB<<" et betaB="<<betaB<<std::endl;

   for (int i=0; i < nH*3; i+=3)
     {
       for(int j=0; j < nW*3; j+=3)
       {
         ImgOut[(j + i*nH)] = alphaR + betaR*ImgIn[(j + i*nH)];
         ImgOut[(j + i*nH)+1] = alphaG + betaG*ImgIn[(j + i*nH)+1];
         ImgOut[(j + i*nH)+2] = alphaB + betaB*ImgIn[(j + i*nH)+2];
       }
     }

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
