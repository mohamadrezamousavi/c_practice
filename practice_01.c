// practice lesson:scanf to receive input and assign in memory
#include <stdio.h>

int main()
{
    int input_num;
    printf("Please Enter your number: ");
    scanf("%d", &input_num);
    printf("Program received your number: %d\n",input_num);
    return 0;
}