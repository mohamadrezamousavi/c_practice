// practice lesson: Array
// Fibonacci Sequence

#include <stdio.h>

int main()
{
    int N;
    printf("Enter number of sequence: ");
    scanf("%d", &N);
    int a[N];
    a[0] = 0;
    a[1] = 1;

    for (int i =2; i < N; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    for (int j = 0; j < N; j++)
    {
        printf("f[%d] = %d\n", j, a[j]);
    }


}