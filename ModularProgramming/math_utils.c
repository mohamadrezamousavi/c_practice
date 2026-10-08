#include "math_utils.h"


static int square (int x){
    return x*x;
}
int sumofsquares(int a, int b){
    return square(a) + square(b);
}