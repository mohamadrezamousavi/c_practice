#include <stdio.h>
#include "math_utils.h"

int main(){
    int a, b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("sum of squares: %d\n", sumofsquares(a,b));
    return 0;
}