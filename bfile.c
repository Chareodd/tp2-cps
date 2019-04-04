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
    bit = (fichier->buffer & (1 << 7)) >> 7 ;
    fichier->buffer = (fichier->buffer << 1) ;
    fichier->length-- ;
    return bit ;
}

int bitwrite(BFILE *fichier, char bit) {
    if (fichier->mode != 'w') return -1 ;
    if (fichier->length < 8) {
        if (bit) {  //bit à 1
        fichier->buffer |= (1 << (7 - fichier->length)) ;
        fichier->length++ ;
        } else {    //bit à 0
            fichier->length++ ;
        }
        if (fichier->length == 8) { //buffer plein
            fichier->length = 0 ;
            fprintf(fichier->f, "%c", fichier->buffer) ;
            fichier->buffer &= 0 ;
        }
    } else {
        fichier->length = 0 ;
        fprintf(fichier->f, "%c", fichier->buffer) ;
        fichier->buffer &= 0 ;
    }
    return 1 ;
}

int beof(BFILE *fichier) {
    if (fichier->buffer == EOF) {
        return 1 ;
    }
    return 0 ;
}