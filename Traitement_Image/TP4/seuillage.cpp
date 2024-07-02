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

   int a0R = 100; int a0G = 100; int a0B = 100;
   int a1R = 200; int a1G = 200; int a1B = 200;
   int s0 = 100; int s1 = 200;
   for (int i=0; i < nH*3; i+=3)
     {
       for(int j=0; j < nW*3; j+=3)
       {
         ImgOut[(i*nW+j)] = ImgIn[(i*nW+j)];
         ImgOut[(i*nW+j)+1] = ImgIn[(i*nW+j)+1];
         ImgOut[(i*nW+j)+2] = ImgIn[(i*nW+j)+2];

         if(ImgOut[(i*nW+j)] < s0) ImgOut[(i*nW+j)] = s0;
         else if(ImgOut[(i*nW+j)] > s1) ImgOut[(i*nW+j)] = s1;

         if(ImgOut[(i*nW+j)+1] < s0) ImgOut[(i*nW+j)+1] = s0;
         else if(ImgOut[(i*nW+j)+1] > s1) ImgOut[(i*nW+j)+1] = s1;

         if(ImgOut[(i*nW+j)+2] < s0) ImgOut[(i*nW+j)+2] = s0;
         else if(ImgOut[(i*nW+j)+2] > s1) ImgOut[(i*nW+j)+2] = s1;
       }
     }

   float alphaR = 255*(a0R/(a1R-a0R));
   float betaR = 255/(a1R-a0R);

   float alphaG = 255*(a0G/(a1G-a0G));
   float betaG = 255/(a1G-a0G);

   float alphaB = 255*(a0B/(a1B-a0B));
   float betaB = 255/(a1B-a0B);

   for (int i=0; i < nH*3; i+=3)
     {
       for(int j=0; j < nW*3; j+=3)
       {
         ImgOut[(j + i*nH)] = alphaR + betaR*ImgOut[(j + i*nH)];
         ImgOut[(j + i*nH)+1] = alphaG + betaG*ImgOut[(j + i*nH)+1];
         ImgOut[(j + i*nH)+2] = alphaB + betaB*ImgOut[(j + i*nH)+2];
       }
     }
     for (int i=0; i < nH*3; i+=3)
       {
         for(int j=0; j < nW*3; j+=3)
         {
           histoR[(int)ImgOut[(i*nW+j)]]++;
           histoG[(int)ImgOut[(i*nW+j)+1]]++;
           histoB[(int)ImgOut[(i*nW+j)+2]]++;
         }
       }
     for(int i=0; i<256; i++) {
       std::cout<< i << " " << histoR[i] <<std::endl;
     }
   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
