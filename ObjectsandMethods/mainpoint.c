#include <stdio.h>
#include "point.h"

int main(){
    Point p = {10, 20};
    point_print(&p);
    point_move(&p, 2,3);
    printf("after move:\n");
    point_print(&p);
}