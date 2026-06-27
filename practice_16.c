// practice lesson: function with pointer parameter, indexing of pointer
// Bubble Sort of 2D-array with pointer 

# include <stdio.h>
# define subarray 10
# define arr_element 2
void printArray(int (*const aptr)[10]);
void bubble3(int (*const aptr)[subarray]);
int main()
{
    int arr[arr_element][subarray] = {{5,3,7,9,0,4,6,2,8,1},{15,18,14,11,19,12,17,13,16,10}};
    int (*aptr)[subarray] =arr; //pointer to first row
    printArray(aptr);
    bubble3(aptr);
    printArray(aptr);
    return 0;
}

void printArray(int (*const aptr)[10])
{
   printf("[2][3] element is: %d\n",*(*(aptr + 1) + 3)); 
   printf("[2][3] address is: %p\n",(*(aptr + 1) + 3));
}

void bubble3(int (*const aptr)[subarray])
{
    for (int i =0; i < 2; i++) //select row
    {
        for (int j=0; j< 10; j++)
        {
            for (int k=0; k<9; k++)
            {
                if ((*(*(aptr+i) + k)) > (*(*(aptr+i) + k + 1)))
                {
                    int tmp = (*(*(aptr+i) + k + 1));
                    (*(*(aptr+i) + k + 1)) = (*(*(aptr+i) + k ));
                    (*(*(aptr+i) + k )) = tmp;

                }
            }
        }
    }
}
