#include "distanc.h"

static int square(int x){
    return x*x;
}
int distance_squared(int x1,int y1,int x2,int y2){
    return square(x2 - x1) + square(y2 - y1);
}