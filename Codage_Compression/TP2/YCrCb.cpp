#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250], cY[250], cCr[250], cCb[250];
  int nH, nW, nTaille, nR, nG, nB, y, cr, cb;

  if (argc != 6)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm y.pgm cr.pgm cb.pgm\n");
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
           nR = ImgIn[(j + i*nH)];
           nG = ImgIn[(j + i*nH)+1];
           nB = ImgIn[(j + i*nH)+2];

           y = 0.257 * nR + 0.504 * nG + 0.098 * nB +  16;
           cr = -0.148 * nR - 0.291 * nG + 0.439 * nB + 128;
           cb = 0.439 * nR - 0.368 * nG - 0.071 * nB + 128;

           ImgOut[(j + i*nH)] = y;
           if((i%2==0) && (j%2==0)) {
             ImgOut[(j + i*nH)+1] = cr;
             ImgOut[(j + i*nH)+2] = cb;
           }
           else if((i%2==0) && (j%2!=0)) {
             ImgOut[(j + i*nH)+1] = ImgOut[((j-3) + i*nH)+1];
             ImgOut[(j + i*nH)+2] = ImgOut[((j-3) + i*nH)+2];
           }
           else if(i%2!=0){
             ImgOut[(j + i*nH)+1] = ImgOut[(j + (i-3)*nH)+1];
             ImgOut[(j + i*nH)+2] = ImgOut[(j + (i-3)*nH)+2];
           }
         }
       }

   for (int i=0; i < nTaille*3; i+=3)
   {
     y = ImgOut[i] - 16;
     cr = ImgOut[i+1] - 128;
     cb = ImgOut[i+2] - 128;

     ImgOut[i] =   1.164 * y              + 1.596 * cb;
     ImgOut[i+1] = 1.164 * y - 0.392 * cr - 0.813 * cb;
     ImgOut[i+2] = 1.164 * y + 2.017 * cr;

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
