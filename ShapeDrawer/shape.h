#ifndef SHAPE_H
#define SHAPE_H

typedef struct Shape Shape;

typedef void (*DrawFunc) (const Shape*);
typedef double (*AreaFunc) (const Shape*);

typedef struct Shape{
    DrawFunc draw_ptr;
    AreaFunc area_ptr;
} Shape;


void process_shape(const Shape *shape);
#endif