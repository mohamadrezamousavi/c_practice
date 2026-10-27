# Encapsulation
## Opaque Pointers Concept
### So far, when we define a struct in a header file, anyone who includes that header can see and directly access all its members. This breaks encapsulation: the principle of hiding internal details from outside code.

### C provides a powerful technique called opaque pointers to solve this. The idea is simple: declare that a struct exists in the header, but don't reveal what's inside it. This is done using an incomplete type:
```
// counter.h
#ifndef COUNTER_H
#define COUNTER_H
typedef struct Counter Counter;  // Declaration only - no body!

Counter *create_counter(int start);
void free_counter(Counter *c);
#endif

```
### This means code that includes this header can only work with pointers to Counter, never the struct itself directly.
---
## Defining Opaque Structs
### The source file is where you define what's actually inside:
```
// counter.c
#include "counter.h"
#include <stdlib.h>

struct Counter {
    int value;      // Hidden from outside!
    int step;
};

Counter *create_counter(int start) {
    Counter *c = malloc(sizeof(Counter));
    c->value = start;
    c->step = 1;
    return c;
}

void free_counter(Counter *c) {
    free(c);
}
```
### The key point: struct Counter { ... } appears only in the .c file. Any file that includes counter.h knows Counter exists but cannot see value or step. Attempting to write c->value in main.c would cause a compiler error: the members are truly invisible. This separation is the foundation of encapsulation in C.
---
## Getters and Setters
### public interfaces that provide controlled access to private data. we read or modify Object with validation
### A getter returns the value of a hidden member:
```
// counter.h
int counter_get_value(const Counter *c);

// counter.c
int counter_get_value(const Counter *c) {
    return c->value;
}
```
### A setter modifies a hidden member:
```
// counter.h
void counter_set_value(Counter *c, int new_value);

// counter.c
void counter_set_value(Counter *c, int new_value) {
    if (new_value < 0) return 0; // Reject invalid input with 0 code
    c->value = new_value;
    return 1; // Success
}
```
```
// main.c
Counter *c = create_counter(10);
printf("%d\n", counter_get_value(c));  // 10
counter_set_value(c, 25);
printf("%d\n", counter_get_value(c));  // 25
```