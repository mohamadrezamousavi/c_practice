#include <stdio.h>
#include "swap.h"

int main(){

    char type;
    printf("Enter your type: ");
    scanf("%c", &type);
    if (type == 'i'){
        int a,b;
        printf("Enter a: ");
        scanf("%d", &a);
        printf("Enter b: ");
        scanf("%d", &b);
        size_t size = sizeof(int);
        generic_swap(&a, &b, size);
        printf("a: %d\n", a);
        printf("b: %d\n", b);
    }
    else if (type == 'd'){
        double a,b;
        printf("Enter a: ");
        scanf("%lf", &a);
        printf("Enter b: ");
        scanf("%lf", &b);
        size_t size = sizeof(double);
        generic_swap(&a, &b, size);   
        printf("a: %.2f\n", a);
        printf("b: %.2f\n", b);             

    }
    return 0;
}