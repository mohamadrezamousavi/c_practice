// Write a C program that demonstrates proper pointer declaration syntax:

# include <stdio.h>

int main ()
{
    int *int_ptr = NULL;
    char *char_ptr = NULL;
    float *float_ptr = NULL;

    int Age = 19;
    char Grade = 'B';
    float Temperature = 25.7;

    int_ptr = &Age;
    char_ptr = &Grade;
    float_ptr = &Temperature;
    
    printf("Address of Age integer is: %p\n", (void *)int_ptr);
    printf("Address of Grade character is: %p\n", (void *)char_ptr);
    printf("Address of Temperature float is: %p\n\n", (void *)float_ptr);

    printf("Values before Change\n\n");

    printf("Value of Age through it's pointer: %d\n", *int_ptr);
    printf("Value of Grade through it's pointer: %c\n", *char_ptr);
    printf("Value of Temperature through it's pointer: %.1f\n\n", *float_ptr);

    *int_ptr += 3;
    *char_ptr+= 3;
    *float_ptr += 3;
    printf("Values after Change\n\n");    
    printf("Value of Age through it's pointer: %d\n", *int_ptr);
    printf("Value of Grade through it's pointer: %c\n", *char_ptr);
    printf("Value of Temperature through it's pointer: %.1f\n", *float_ptr);    
    return 0;
}