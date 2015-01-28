#include <stdio.h>

// Get the kth bit *from the right*
int kth_bit_from_right(int n, int k) {
    return (n & ( 1 << k )) >> k;
}

// Set the kth bit from the right
int set_kth_bit_from_right(int n, int k) {
    return n | (1 << k);    
}

// Unset the kth bit from the right
int unset_kth_bit_from_right(int n, int k) {
    return n & ~(1 << k);
}

// Assumes little endian
void print_bits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0;j --) {
            byte = b[i] & (1 << j);
            byte >>= j;
            printf("%u", byte);
        }
    }

    puts("");
}