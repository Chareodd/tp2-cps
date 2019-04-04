#include "bfile.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  BFILE *bfichier;
  int c;
 
  bfichier = bstart(stdout,"w");
  if (bfichier == NULL)
    {
      fprintf(stderr,"Erreur d'ouverture d'acces binaire en ecriture\n");
      exit(3);
    }
  c = getchar();
  while (!feof(stdin))
    {
      switch (c)
        {
        case '0':
          if ((bfichier->length == 7) || (bfichier->length == 8)) {
            fprintf(bfichier->f, "%c", 0xFF) ;
            fprintf(bfichier->f, "%c", 0xFF) ;
          }
          bitwrite(bfichier,0);
          break;
        case '1':
          if ((bfichier->length == 7) || (bfichier->length == 8)) {
            fprintf(bfichier->f, "%c", 0xFF) ;
            fprintf(bfichier->f, "%c", 0xFF) ;
          }
          bitwrite(bfichier,1);
          break;
        }
      c = getchar();
    }
  fprintf(bfichier->f, "%c", 0xFF) ;
  switch (bfichier->length) {
    case 0 :
      fprintf(bfichier->f, "%c", 0x00) ;
      break;
    case 1 :
      fprintf(bfichier->f, "%c", 0x01) ;
      break;
    case 2 :
      fprintf(bfichier->f, "%c", 0x02) ;
      break;
    case 3 :
      fprintf(bfichier->f, "%c", 0x03) ;
      break;
    case 4 :
      fprintf(bfichier->f, "%c", 0x04) ;
      break;
    case 5 :
      fprintf(bfichier->f, "%c", 0x05) ;
      break;
    case 6 :
      fprintf(bfichier->f, "%c", 0x06) ;
      break;
    case 7 :
      fprintf(bfichier->f, "%c", 0x07) ;
      break;
  }
  fprintf(bfichier->f, "%c", bfichier->buffer) ;
  bstop(bfichier);
  return 0;
}
