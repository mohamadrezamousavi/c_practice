#include <stdlib.h>
#include "box.h"

struct Box{
    int width;
    int height;
    int depth;
};

Box *create_Box(int width, int height, int depth){
    Box *b = malloc(sizeof(Box));
    b->width = width;
    b->height = height;
    b->depth = depth;
    return b;
}
void destroy_box(Box *self){
    if (self == NULL) return;
    free(self);
}
int get_volume(Box *self){
    return (self->width * self->height * self->depth);
}

int set_box(Box *self, int new_width, int new_height, int new_depth){
    if (self->width <= 0 || self->height <= 0 || self->depth <= 0){
        return 0;
    }
    else{
        self->width = new_width;
        self->height = new_height;
        self->depth = new_depth;
        return 1;
    }
}