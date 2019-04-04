#include "bfile.h"
#include <stdlib.h>

BFILE *bstart(FILE *fichier, const char *mode) {
    BFILE* f = (BFILE*) malloc(sizeof(BFILE)) ;
    if (f) {
        f->mode = *mode ;
        f->length = 0 ;
        f->f = fichier ;
        f->buffer &= 0 ;
    }
    return f ;
}

int bstop(BFILE *fichier) {
    if (fichier->buffer) {
        fprintf(fichier->f, "%c", fichier->buffer) ;
    }
    free(fichier) ;
    return 0 ;
}

char bitread(BFILE *fichier) {
    if (fichier->mode != 'r') return -1 ;
    if (fichier->length == 0) {
        fichier->buffer = fgetc(fichier->f) ;
        if (fichier->buffer != EOF) {
            fichier->length = 8 ;
        } else {    //EOF
            return -1 ;
        }
    }
    char bit ;
    bit &= 0 ;
    bit = fichier->buffer & 1 ;
    fichier->buffer = (fichier->buffer >> 1) & ~(1 << 7) ;
    fichier->length-- ;
    return bit ;
}

int bitwrite(BFILE *fichier, char bit) {
    if (fichier->mode != 'w') return -1 ;
    if (fichier->length == 8) {
        fichier->length = 0 ;
        fprintf(fichier->f, "%c", fichier->buffer) ;
        fichier->buffer &= 0 ;
    }
    if (bit) {
        fichier->buffer |= (1 << fichier->length) ;
        fichier->length++ ;
    }
    return 1 ;
}

int beof(BFILE *fichier) {
    if (fichier->buffer == EOF) {
        return 1 ;
    }
    return 0 ;
}