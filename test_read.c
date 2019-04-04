#include <stdio.h>
#include <stdlib.h>
#include "bfile.h"

int main()
{
  BFILE* bfichier;
 
  bfichier = bstart(stdin,"r");
  if (bfichier == NULL)
    {
      fprintf(stderr,"Erreur d'ouverture d'acces binaire en lecture\n");
      exit(3);
    }
  unsigned char c = fgetc(bfichier->f) ;
  unsigned char dir = fgetc(bfichier->f) ;
  while (!beof(bfichier))
    {
      switch (c)  //on regarde l'octet réservé
        {
      case 0xFF:
        switch (dir) {  //on regarde la directive
          case 0xFF :
            for (int i = 0 ; i < 8 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x00 :
            break ;
          case 0x01 :
            for (int i = 0 ; i < 1 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x02 :
            for (int i = 0 ; i < 2 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x03 :
            for (int i = 0 ; i < 3 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x04 :
            for (int i = 0 ; i < 4 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x05 :
            for (int i = 0 ; i < 5 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x06 :
            for (int i = 0 ; i < 6 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          case 0x07 :
            for (int i = 0 ; i < 7 ; i++) {
              if (bitread(bfichier)) {
                printf("1") ;
              } else {
                printf("0") ;
              }
            }
            break ;
          default : 
            printf("probDir") ;
        }
        break;
      default:
        printf("probC");
        }
      
      if (dir != 0xFF) {  //si on arrive la, on est à la fin
        bstop(bfichier);
        return 0;
      }
      c = fgetc(bfichier->f) ;
      dir = fgetc(bfichier->f) ;
    }
  bstop(bfichier);
  return 0;
}
