// practice lesson: Repetition while
// Sum and Mean
#include <stdio.h>

int main ()
{
    int num,sum;
    float mean;
    int i = 0;
    sum =0;
    while (i < 10)
    {
        printf("Enter a Number:");
        scanf("%d", &num);
        sum+= num;
        i++;
    }
    mean = (float)sum / 10;

    printf("Sum is: %d\n", sum);
    printf("Mean is: %.2f\n", mean);
    return 0;
}