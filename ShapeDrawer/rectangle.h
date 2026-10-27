
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

typedef struct {
    Shape shape;
    double width;
    double height;
} Rectangle;

Rectangle create_rectangle(double width, double height);


#endif