# include <stdio.h>

int Calculate_Sum (int *ptr, int size);

int main ()
{
    int Scores[] = {10, 20, 30, 40, 50};
    int *ptr = Scores;
    int size = sizeof(Scores)/sizeof(*ptr);
    Calculate_Sum(ptr, size);
 

    return 0;
}

int Calculate_Sum (int *ptr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(ptr + i);
        printf("Scores[%d] is %d\n", i, *(ptr+i));
    }

    printf("Sum is: %d\n", sum);
}
