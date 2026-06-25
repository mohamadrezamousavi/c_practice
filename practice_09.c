// practice lesson: Array
// using math lib and -lm to link to it
#include <stdio.h>
#include<math.h>

int main()
{
    int p[] = {0,3,1,0,8,7,9,5,
               6,4,3,4,0,1,2,6,
               5,3,1,0,2,6,5,4};
    
    int array_size = sizeof(p)/sizeof(p[0]);

    printf("array size is: %d\n", array_size);
    int digits[10];
    int sum;
    float mean;
    float stdev;
    
    for ( int i=0; i < array_size; i++)
    {
        digits[p[i]]++;
        sum += p[i];
        
    }
    for (int j=0; j < 10; j++)
    {
        printf("%d, ", digits[j]);
    }

    printf("\nSum of array elements: %d", sum);
    mean = (float)sum / array_size;
    printf("\nmean of array elements: %.2f", mean);

    for (int k=0; k<array_size; k++)
    {
        stdev += (p[k] - mean) * (p[k] - mean);
    }
    stdev = sqrt(stdev/(array_size - 1));
    printf("\nstdev of array elements: %.2f", stdev);

    printf("\n");
    printf("\nDigit\tCount\thistogram\n");
    
    for (int i = 0; i< 10; i++)
    {
        printf("%d\t%d\t",i,digits[i]);
        for (int k=0; k < digits[i]; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}