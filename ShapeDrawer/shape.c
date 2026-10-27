#include <stdio.h>
#include "shape.h"

void process_shape(const Shape *shape){

    shape->draw_ptr(shape);
    printf("Area: %.2f\n", shape->area_ptr(shape));
};