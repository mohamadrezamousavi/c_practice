# Function Pointers
## Declaring Function Pointers
### So far, we've learned to simulate inheritance using struct embedding. But true polymorphism, where different objects respond differently to the same call, requires something more: function pointers.
### A function pointer is a variable that stores the address of a function. Just like a regular pointer holds the address of data, a function pointer holds the address of executable code.
```
int (*operation)(int, int);
```
### This declares a variable called operation that can point to any function that takes two int parameters and returns an int. The parentheses around *operation are crucial, without them, you'd be declaring a function that returns a pointer.
```
int add(int a, int b) {
    return a + b;
}

int (*operation)(int, int);
operation = add;  // Now operation points to add
```
### To assign a function to this pointer, simply use the function's name (without parentheses). The function name acts as its address. You can also use &add explicitly, but it's optional: both forms are equivalent in C.
---
## Calling Function Pointers
### calling the functions through that pointer
``` 
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int main() {
    int (*operation)(int, int) = add;    
    int result = operation(5, 3);  // Calls add(5, 3)
    printf("%d\n", result);        // Output: 8
    operation = subtract;
    result = operation(5, 3);     // Now calls subtract(5, 3)
    printf("%d\n", result);       // Output: 2
    return 0;
}
```
### The same variable operation now executes completely different logic. This ability to swap behavior at runtime is the foundation of polymorphism in C.
---
## Typedef for Function Pointers
### The typedef keyword lets you create an alias for any type, including function pointers. Instead of writing the full declaration every time, you define the type once and use the alias throughout your code.
```
typedef int (*Operation)(int, int);

Operation op1;
Operation op2;
---------------------------------------
typedef int (*Operation)(int, int);

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {
    Operation op1 = add;
    Operation op2 = multiply;
    
    printf("%d\n", op1(3, 4));  // Output: 7
    printf("%d\n", op2(3, 4));  // Output: 12
    return 0;
}
```
### This approach is especially valuable when passing function pointers as parameters or storing them in structs: situations you'll encounter frequently as we build toward polymorphism.
---
## Passing Functions as Arguments
### One of the most powerful uses of function pointers is passing them as arguments to other functions. This allows you to inject custom behavior into a function without modifying its code: a technique sometimes called a callback.
```
typedef int (*Operation)(int, int);
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int compute(int a, int b, Operation op) {
    return op(a, b);
}
int main() {
    printf("%d\n", compute(5, 3, add));       // Output: 8
    printf("%d\n", compute(5, 3, multiply));  // Output: 15
    return 0;
}
```
### Notice how the same compute function produces different results based on which function we pass. This pattern is fundamental to writing flexible, reusable code. You write the structure once, and users of your function supply the specific logic they need.
