#ifndef SHAPE_H
#define SHAPE_H

typedef struct{
    int color;
} Shape;

typedef struct{
    Shape shape;
    int width;
    int height;
} Rect;

void set_color(Shape *self, int new_color);
void print_rect(Rect *self);
#endif