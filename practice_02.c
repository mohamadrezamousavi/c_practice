// practice lesson: basic operators
#include <stdio.h>

int main()
{
    int num1,num2,sum,mult;
    printf("Enter your first number: \n");
    scanf("%d", &num1);
    printf("Enter your second number: \n");
    scanf("%d", &num2); 
    sum = num1 + num2;
    mult = num1 * num2;
    printf("Sum is: %d\n", sum);  
    printf("mult is: %d\n", mult); 
    return 0;
}