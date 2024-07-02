#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, nR, nG, nB;

  if (argc != 3)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = (nH * nW);

   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nTaille);
   allocation_tableau(ImgOut, OCTET, 256*3);

   srand (time(NULL));
   int k = 256;
   int c[k];
   int profondeur = 10;

   int r[k], g[k], b[k]; //rgb initial du cluster k
   int mR[k], mG[k], mB[k], nC[k]; //rgb moyen du cluster k
   int min_distance, cId;
   int classe[nTaille];

   int psnr = 0;

   //initialisation
   for(int i=0; i<k; i++) {
     c[i] = rand() % nTaille;
     r[i] = ImgIn[(c[i]*3)];
     g[i] = ImgIn[(c[i]*3)+1];
     b[i] = ImgIn[(c[i]*3)+2];
     for(int j=0; j<i; j++) { //on évite les doublons
       while(i!=j && (r[i]==r[j] && g[i]==g[j] && b[i]==b[j])) {
         c[i] = rand() % nTaille;
         r[i] = ImgIn[(c[i]*3)];
         g[i] = ImgIn[(c[i]*3)+1];
         b[i] = ImgIn[(c[i]*3)+2];
       }
     }
     mR[i]=0; mG[i]=0; mB[i]=0;
     nC[i]=0; min_distance=999999999; cId=0;
   }

   for(int j=0; j < profondeur; j++) {
     for (int i=0; i < nTaille*3; i+=3)
       {
         nR = ImgIn[i];
         nG = ImgIn[i+1];
         nB = ImgIn[i+2];

         for(int x=0; x<k; x++) {
           int distance = sqrt(pow(r[x]-nR,2) + pow(g[x]-nG,2) + pow(b[x]-nB,2));
           if (distance <= min_distance) {
             cId = x;
             min_distance = distance;
           }
         }

         nC[cId]++;
         classe[i/3] = cId;

         mR[cId] += nR;
         mG[cId] += nG;
         mB[cId] += nB;

         min_distance=999999999;
       }
       for(int i=0; i<k; i++) {
         if(nC[i] != 0) {
           r[i] = mR[i]/nC[i];
           g[i] = mG[i]/nC[i];
           b[i] = mB[i]/nC[i];
         }
         /* Génération de palette
         if(j==profondeur-1) {
           ImgOut[(i*3)] = mR[i]/nC[i];
           ImgOut[(i*3)+1] = mG[i]/nC[i];
           ImgOut[(i*3)+2] = mB[i]/nC[i];
         }
         */
         mR[i]=0; mG[i]=0; mB[i]=0; nC[i]=0;
       }
   }

   for (int i=0; i < nTaille*3; i+=3)
   {
     ImgOut[i] = r[classe[i/3]];
     ImgOut[i+1] = g[classe[i/3]];
     ImgOut[i+2] = b[classe[i/3]];
     psnr += pow(ImgOut[i]-ImgIn[i],2) + pow(ImgOut[i+1]-ImgIn[i+1],2) + pow(ImgOut[i+2]-ImgIn[i+2],2);
     /* couleurs initiales
     ImgOut[i] = ImgIn[c[classe[i/3]]];
     ImgOut[i+1] = ImgIn[c[classe[i/3]]+1];
     ImgOut[i+2] = ImgIn[c[classe[i/3]]+2];
     */
   }
   psnr /= 3*nTaille;
   psnr = 10 * log10(255*255/psnr);

   std::cout<<"PSNR = "<<psnr<<std::endl;

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  16, 16);
   free(ImgIn);
   return 1;
}
