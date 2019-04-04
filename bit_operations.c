#include "bit_operations.h"

int get_bit(int32_t n, int i) {
    return (n >> i) & 1 ;
}

int32_t set_bit(int32_t n, int i) {
    n |= (1 << i) ;
    return n ;
}

int32_t clr_bit(int32_t n, int i) {
    n &= ~(1 << i) ;
    return n ;
}