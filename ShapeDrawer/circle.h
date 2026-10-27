#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H
typedef struct {
    Shape shape;
    double radius;
} Circle;

Circle create_circle(double radius);



#endif