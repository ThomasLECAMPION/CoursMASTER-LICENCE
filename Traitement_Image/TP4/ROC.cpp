#include <iostream>
#include <stdio.h>
#include "image_ppm.h"
//1116
int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgLue2[250], cNomImgEcrite[250];
  int nH, nW, nTaille;

  if (argc != 4)
     {
       printf("Usage: ImageIn.ppm ImageSeuil.pgm ImageOut.ppm\n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue);
   sscanf (argv[2],"%s",cNomImgLue2);
   sscanf (argv[3],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgSeuil, *ImgOut;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgSeuil, OCTET, nTaille);
   lire_image_pgm(cNomImgLue2, ImgSeuil, nH * nW);

   allocation_tableau(ImgOut, OCTET, nTaille*3);

   int a, b, c, d, e, f, g, h, i;

   for (int y=0; y < nH*3; y+=3)
     {
       for(int x=0; x < nW*3; x+=3)
       {
         a = ((x-1) + (y-1)*nH);
         b = (x + (y-1)*nH);
         c = ((x+1) + (y-1)*nH);

         d = ((x-1) + y*nH);
         e = (x + y*nH);
         f = ((x+1) + y*nH);

         g = ((x-1) + (y+1)*nH);
         h = (x + (y+1)*nH);
         i = ((x+1) + (y+1)*nH);

         if(ImgSeuil[e/3] == 255) {
           if((y!=0 && y!=(nH*3)-1) && (x!=0 && x!=(nW*3)-1)) {
             //std::cout<<"y="<<y<<" x="<<x<<std::endl;
             ImgOut[e] = round((ImgIn[a]+ImgIn[b]+ImgIn[c]+ImgIn[d]+ImgIn[e]+ImgIn[f]+ImgIn[g]+ImgIn[h]+ImgIn[i])/9);
             //std::cout<<"ROUGE: "<<(int)ImgOut[e]<<std::endl;
             ImgOut[e+1] = round((ImgIn[a+1]+ImgIn[b+1]+ImgIn[c+1]+ImgIn[d+1]+ImgIn[e+1]+ImgIn[f+1]+ImgIn[g+1]+ImgIn[h+1]+ImgIn[i+1])/9);
             //std::cout<<"VERT: "<<(int)ImgOut[e+1]<<std::endl;
             ImgOut[e+2] = round((ImgIn[a+2]+ImgIn[b+2]+ImgIn[c+2]+ImgIn[d+2]+ImgIn[e+2]+ImgIn[f+2]+ImgIn[g+2]+ImgIn[h+2]+ImgIn[i+2])/9);
             //std::cout<<"BLEU: "<<(int)ImgOut[e+2]<<std::endl;
           }
         }
         else {
           ImgOut[e] = ImgIn[e];
           ImgOut[e+1] = ImgIn[e+1];
           ImgOut[e+2] = ImgIn[e+2];
         }
       }
     }

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
