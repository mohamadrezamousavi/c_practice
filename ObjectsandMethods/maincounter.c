#include <stdio.h>
#include "counter.h"

int main() {
    // Read input
    int starting_value;
    int num_increments;
    printf("Enter Starting Value: ");
    scanf("%d", &starting_value);
    printf("Enter Number of Increment: ");
    scanf("%d", &num_increments);
    Counter c = {starting_value};
    for (int i = 0; i < num_increments; i++){
        counter_increment(&c);
    }
    
    printf("Value is: %d\n", counter_get(&c));
    return 0;
}