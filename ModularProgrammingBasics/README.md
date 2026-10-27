## Modular Programming Basics
### Header Files
#### A header file (with the .h extension) contains function declarations (also called prototypes). Header files separates what a function does from how it does it. These declarations tell the compiler that a function exists and what parameters it takes, without providing the actual implementation.
```
// in math_utils.h file:
int add (int a, int b);

// in main.c file:

#include "math_utils.h"

```

### Source Files
#### The next step in modular programming is moving definitions of functions code into their own source files (.c files).
```
// in math_utils.h file:
int add(int a, int b);  //declaration

--------------------------------------

//in math_utils.c file:
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

--------------------------------------

//in main.c file:
#include <stdio.h>
#include "math_utils.h"

int main() {
    printf("%d\n", add(5, 3));
    return 0;
}

```

### Include Guards
#### When a header file gets included multiple times in a project, the compiler sees the same declarations repeatedly, causing errors. This commonly happens when multiple files include the same header, or when headers include each other. Include guards solve this problem. An include guard uses three preprocessor directives to ensure a header's contents are processed only once:

```
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);

#endif

```
### Static Functions
#### sometimes you need helper functions that should only be used internally: functions that other files shouldn't access or even know about.
#### The static keyword, when applied to a function, restricts its visibility to the file where it's defined. This creates a private function that cannot be called from other source files, even if someone tries to declare it.
```
// math_utils.c
#include "math_utils.h"

// Private helper - only visible in this file
static int square(int x) {
    return x * x;
}

// Public function - can be called from main.c
int sum_of_squares(int a, int b) {
    return square(a) + square(b);
}

```