#include <stdio.h>
#include "point.h"

void point_print(const Point *self){
    printf("current point: (%d, %d)\n", self->x, self->y);
}
void point_move(Point *self, int dx, int dy){
    self->x += dx;
    self->y += dy;
}