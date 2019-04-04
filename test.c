#include "lib.h"
#include <stdio.h>

int main() {
    FILE* f ;
    f = fopen("fichier.txt", "w") ;
    BFILE* bf = bstart(f, "w") ;
    return 0 ;
}