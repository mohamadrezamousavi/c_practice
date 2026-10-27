#include <stdio.h>
#include "shape.h"

int main(){
    int width, height, color, new_color;
    printf("Enter Width: ");
    scanf("%d", &width);
    printf("Enter Height: ");
    scanf("%d", &height);
    printf("Enter Color: ");
    scanf("%d", &color);
    printf("Enter New Color: ");
    scanf("%d",&new_color);

    Rect rect = {{color}, width, height};
    set_color((Shape *)&rect, new_color);
    print_rect(&rect);

}