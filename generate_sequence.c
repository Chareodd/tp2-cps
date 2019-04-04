#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

int main() {
    int length;
    struct timeval tm;

    gettimeofday(&tm, NULL);
    srandom(tm.tv_usec);
    length = random()%100+10;
    while (length--)
        printf("%ld", random()%2);
    printf("\n");
    return 0;
}
