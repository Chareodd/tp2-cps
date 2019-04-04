#include <stdio.h>

typedef struct b {
    FILE* f ;
    char buffer ;   //le tampon
    int length ;    //le nombre de bit utilisé du tampon
    char mode ;  //le mode
} BFILE ;

BFILE *bstart(FILE *fichier, const char *mode) ;

int bstop(BFILE *fichier) ;

char bitread(BFILE *fichier) ;

int bitwrite(BFILE *fichier, char bit) ;

int beof(BFILE *fichier) ;