#ifndef BOX_H
#define BOX_H

typedef struct Box Box;

Box *create_Box(int width, int height, int depth);
void destroy_box(Box *self);
int get_volume(Box *self);
int set_box(Box *self, int new_width, int new_height, int new_depth);



#endif