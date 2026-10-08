#include <stdio.h>
#include "calc.h"

int main(){
    int a,b,c;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);  
    printf("Enter c: ");
    scanf("%d", &c);
    printf("Sum of a and b: %d\n",add(a,b));  
    printf("Sub of c from a: %d\n",subtract(b,c));  
    printf("prod of b and c: %d\n",multiply(b,c));  
    return 0;
}