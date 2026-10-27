#include <stdio.h>
#include "circle.h"

static void draw_circle(const Shape *shape){
    const Circle* circle = (const Circle*)shape;
    printf("Drawing Circle with radius: %.2f\n", circle->radius);
}

static double area_circle(const Shape *shape){
    const Circle *circle =(const Circle*) shape;
    return (3.14159 * circle->radius * circle->radius);
}

Circle create_circle(double radius){
    Circle circle;
    circle.shape.draw_ptr = draw_circle;
    circle.shape.area_ptr = area_circle;
    circle.radius = radius;
    return circle;
}
