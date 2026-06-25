// practice lesson: function with arrays input, working on indices
// Bubble Sort

#include <stdio.h>
# define N 10
void bubble(int array_in[]);
int main()
{
    int arr[N] = {3,1,0,2,9,6,4,7,8,5};
    bubble(arr);
    printf("Bubble Sorted Array Is: {");
    for(int i=0; i<N-1; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("%d}\n",arr[N-1]);
    

}

void bubble(int array_in[])
{
    for (int i =0; i < N; i++) //pass
    {
        for (int k=0; k <N-1; k++) //swap
        {
            if (array_in[k]> array_in[k+1])
            {
                int tmp = array_in[k+1];
                array_in[k+1] = array_in[k];
                array_in[k] = tmp;
            }
        }
        
    }
}