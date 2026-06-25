// practice lesson: Basic Pointer
// call by value and call by reference functions

#include<stdio.h>

void func1(int a); 
int func2(int a);
void func3(int *aptr);

int main()
{
    int a = 10;
    printf("a befor function1: %d\n",a);
    func1(a); //call by value without assignment
    printf("a after function1: %d\n",a);
    a = func2(a); //call by value
    printf("a after function2: %d\n",a);
    func3(&a);   //call by reference
    printf("a after function3: %d\n",a);

}

void func1(int a)
{
    a *= 2;
    printf("inside func1 a is: %d\n", a);
}

int func2(int a)
{
    a *= 2;
    printf("inside func2 a is: %d\n", a);
    return a;
}

void func3(int *aptr)
{
    *aptr *= 2;
    printf("inside func3 a is: %d\n", *aptr);
}