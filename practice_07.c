// practice lesson: Recursive function
// Fibonacci Sequence

#include<stdio.h>
int fibonacci(int count);

int main()
{
    int num;
    int sequence_number;
    printf("Enter number of sequence: ");
    scanf("%d",&sequence_number);

    for (num =0; num < sequence_number; num++)
    {
        printf("F(%d) = %d\n", num,fibonacci(num));
    }

    return 0;
}

int fibonacci(int count)
{
    
    if (count == 0) return 0;
    if (count == 1) return 1;
    return fibonacci(count -1) + fibonacci(count -2);
}