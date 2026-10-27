#include <stdio.h>
#include "rectangle.h"

static void draw_rectangle(const Shape *shape){
    const Rectangle * rectangle = (const Rectangle*) shape;
    printf("drawing rectangle with width %.2f and height %.2f\n", rectangle->width, rectangle->height);
}

static double area_rectangle(const Shape *shape){
    const Rectangle *rectangle = (const Rectangle*) shape;
    return rectangle->width * rectangle->height;
}

Rectangle create_rectangle(double width, double height){
    Rectangle rectangle;
    rectangle.height = height;
    rectangle.width = width;
    rectangle.shape.draw_ptr = draw_rectangle;
    rectangle.shape.area_ptr = area_rectangle;
    return rectangle;
//    rectangle.shape.draw_ptr(&rectangle.shape);
//    printf("area: %.2f\n", rectangle.shape.area_ptr(&rectangle.shape));
}