// practice lesson: constant content to function
// Divisors of a number
# include <stdio.h>
int divisor_count(const int number);
int main()
{
    int num;
    printf("Enter your number: ");
    scanf("%d", &num);
    int divisor_num = divisor_count(num) ;
    int arr[divisor_num];
    int array_indice;
    for (int i =1; i < num; i++)
    {
        if ((num%i) == 0)
        {
            arr[array_indice] = i;
            array_indice++;
   
        }
    }

    for (int k =0; k<divisor_num; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}

int divisor_count(const int number)
{
    int divisor_num=0;
    for (int i =1; i < number; i++)
    {
        if ((number%i) == 0)
        {
            divisor_num++;
        }
    }

    printf("Number of Divisors: %d\n", divisor_num);

    return divisor_num;
}