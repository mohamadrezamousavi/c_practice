#include "swap.h"

void generic_swap(void *a, void *b, size_t size){
    char temp [size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b,temp, size);
}