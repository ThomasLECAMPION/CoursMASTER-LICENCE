#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250], cY[250], cCr[250], cCb[250];
  int nH, nW, nTaille, nR, nG, nB;

  if (argc != 6)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%s",cY);
   sscanf (argv[4],"%s",cCr);
   sscanf (argv[5],"%s",cCb);

   OCTET *ImgIn, *ImgOut, *ImgY, *ImgCr, *ImgCb;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   int nTaille3 = nTaille * 3;
   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille3);
   allocation_tableau(ImgY, OCTET, nTaille);
   allocation_tableau(ImgCr, OCTET, nTaille);
   allocation_tableau(ImgCb, OCTET, nTaille);

     for (int i=0; i < nH*3; i+=3)
       {
         for(int j=0; j < nW*3; j+=3)
         {
           ImgOut[(j + i*nH)+1] = ImgIn[(j + i*nH)+1];
           if((i%2==0) && (j%2==0)) {
             ImgOut[(j + i*nH)] = ImgIn[(j + i*nH)];
             ImgOut[(j + i*nH)+2] = ImgIn[(j + i*nH)+2];
           }
           else if((i%2==0) && (j%2!=0)) {
             ImgOut[j + i*nH] = ImgIn[(j-3) + i*nH];
             ImgOut[(j + i*nH)+2] = ImgIn[((j-3) + i*nH)+2];
           }
           else if(i%2!=0){
             ImgOut[j + i*nH] = ImgIn[j + (i-3)*nH];
             ImgOut[(j + i*nH)+2] = ImgIn[(j + (i-3)*nH)+2];
           }
         }
       }

   for (int i=0; i < nTaille*3; i+=3)
   {
     ImgY[i/3] = ImgOut[i];
     ImgCr[i/3] = ImgOut[i+1];
     ImgCb[i/3] = ImgOut[i+2];
   }

   int psnr = 0;

   for (int i=0; i < nTaille*3; i+=3)
   {
     psnr += pow(ImgOut[i]-ImgIn[i],2) + pow(ImgOut[i+1]-ImgIn[i+1],2) + pow(ImgOut[i+2]-ImgIn[i+2],2);
   }
   psnr /= 3*nTaille;
   psnr = 10 * log10(255*255/psnr);

   std::cout<<"PSNR = "<<psnr<<std::endl;

   ecrire_image_pgm(cY, ImgY,  nH, nW);
   ecrire_image_pgm(cCr, ImgCr,  nH, nW);
   ecrire_image_pgm(cCb, ImgCb,  nH, nW);
   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
