#include <stdio.h>
#include "box.h"

int main(){
    int width = 5;
    int height = 5;
    int depth = 5;

    Box *b = create_Box(width, height, depth);
    printf("Volume is: %d\n", get_volume(b));
    int validation;
    validation = set_box(b, 4, 5, 6);
    if (validation == 0)
        printf("Invalid Input");
    else{
        printf("Valid change\n");
        printf("New Volume: %d\n", get_volume(b));
    }
    destroy_box(b);
    printf("Box freed\n");
    
    
}