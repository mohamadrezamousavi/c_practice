// practice lesson: Pointer Cocept
#include <stdio.h>

int main()
{
    int x = 10;
    int *xptr = &x; // xptr store address of an int variable or xptr is a pointer of an int 
    printf("Address of x is: %p\n", (void *)&x);
    printf("Address stored in xptr is: %p\n", (void *)xptr);
    *xptr = 15; // go to the address stored in xptr and change it's value to 15
    printf("value of x is: %d\n", x);
    printf("value of address stored in xptr is: %d\n", *xptr);    
    return 0;
}