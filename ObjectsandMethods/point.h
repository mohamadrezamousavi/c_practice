#ifndef POINT_H
#define POINT_H
typedef struct{
    int x;
    int y;
} Point;

void point_move(Point *self, int dx, int dy);
void point_print(const Point *self);

#endif