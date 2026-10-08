#include <stdio.h>
#include "distanc.h"

int main(){
    int x1, y1, x2, y2;
    printf("Enter x1: ");
    scanf("%d", &x1);
    printf("Enter y1: ");
    scanf("%d", &y1);
    printf("Enter x2: ");
    scanf("%d", &x2);
    printf("Enter y2: ");
    scanf("%d", &y2);

    printf("Squared distance: %d\n", distance_squared(x1,y1,x2,y2));
}