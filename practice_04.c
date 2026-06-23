// practice lesson: Repetition while 2
// Arithmetic Sequence
// a  a+d  a+2d  ...  a+(n-1)d
#include <stdio.h>

int main()
{
    int a,d,n;
    printf("Enter fisrt term \"a\": ");
    scanf("%d",&a);
    printf("Enter difference \"d\": ");
    scanf("%d",&d);
    printf("Enter number of terms term \"n\": ");
    scanf("%d",&n);
    
    int i = 0;
    int id;
    int sumi;
    printf("Sequence: ");
    while(i<n)
    {
        id = d * i;
        sumi = a + id;
        printf("%d\t", sumi);
        i++;
    }
    printf("\n");
    return 0;
}