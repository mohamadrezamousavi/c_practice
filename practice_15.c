// practice lesson: function with pointer parameter, indexing of pointer
// Bubble Sort of array with pointer 
# include <stdio.h>
# define subarray 10
# define arr_element 2

void printArray(int *const aptr);
void bubble2 (int *const aptr);
int main()
{
    //int arr[arr_element][subarray] = {{5,3,7,9,0,4,6,2,8,1},{15,18,14,11,19,12,17,13,16,10}};
    int arr[subarray] = {5,3,7,9,0,4,6,2,8,1};
    int *aptr = arr;
    printArray(aptr); // pointer is it's argument
    bubble2(aptr);
    printArray(aptr);
    return 0;
}

void printArray(int *const aptr)
{
    printf("value of 3rd element of array: %d\n", *(aptr+2));
    printf("Address of 3rd element of array: %p\n", (aptr+2));
    printf("array = {");
    for (int i = 0; i < subarray; i++)
    {
        
        printf("%d ", *(aptr+i));
    }
    printf("}\n");
}

void bubble2 (int *const aptr)
{
    for (int i=0; i < subarray; i++)
    {
        for (int j=0; j <subarray -1; j++)
        {
            if (*(aptr + j) > *(aptr + j + 1))
            {
                int tmp = *(aptr + j + 1);
                *(aptr + j + 1) = *(aptr + j);
                *(aptr + j) = tmp;
            }
        }
    }
}