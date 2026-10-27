#include <stdio.h>
#include "shape.h"

void set_color(Shape *self, int new_color){
    self->color = new_color;
}

void print_rect(Rect *self){
    printf("Rect Width: %d\n", self->width);
    printf("Rect Height: %d\n", self->height);
    printf("Rect Shape Color: %d\n", self->shape.color);
}