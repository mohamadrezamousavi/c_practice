#include <stdio.h>
#include "iterator.h"

int main(){
   int n;
   printf("Enter Number of elements in array: ");
   scanf("%d", &n);
   int arr[n];
   for (int i =0; i < n; i++){
    scanf("%d", &arr[i]);
   } 

   IntIterator it = create_iterator(arr, n);

   while(has_next(&it)){
    printf("%d\n", next(&it));
   }
}