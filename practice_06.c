// practice lesson:using function, forloop, do while
// Prime Number
#include <stdio.h>

#define True 1
#define False 0

int isPrime(int a);

int main()
{
    int num;


    do
    {
        printf("Enter your number: ");
        scanf("%d", &num);
        if (num <= 0 )
        {
            printf("Your Number should be greater than 1\n");
            break;
        }

        if (isPrime(num))
        {
            printf("%d is Prime\n", num);
        }
        else
        {
            printf("%d is not Prime\n", num);
        }   /* code */
    } while (num > 0);
    
    return 0;
}

int isPrime (int a)
{
    int prime = True;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            prime = False;
            break;
        }

        
    }
    return prime;
}