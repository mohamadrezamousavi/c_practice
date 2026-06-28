// practice lesson: Pointer to a pointer

# include <stdio.h>

void findMinMax(int *aptr, int size, int **min_ptr_ptr, int **max_ptr_ptr);
int main()
{
    int arr[] = {14,16,1,2,7,19,16,17,10,11,2,7,8,6,1,20,12,18,15};
    int *aptr = arr;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int *min_ptr = NULL;
    int *max_ptr = NULL;
    findMinMax(aptr, arr_size, &min_ptr, &max_ptr);
    printf("value of min is %d\n", *min_ptr);
    printf("value of max is %d\n", *max_ptr);   
    return 0;
}

void findMinMax(int *aptr, int size, int **min_ptr_ptr, int **max_ptr_ptr)
{
    *min_ptr_ptr = aptr;
    *max_ptr_ptr = aptr;
    for (int i=0; i < size ; i++)
    {
        if (*(aptr + i) < **min_ptr_ptr)
        {
           *min_ptr_ptr = (aptr + i ); 
        }
        if (*(aptr + i) > **max_ptr_ptr)
        {
            *max_ptr_ptr = (aptr + i );
        }

    }
}

