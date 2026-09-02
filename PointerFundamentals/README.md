## Pointer Fundamentals
#### A pointer is a special type of variable that doesn't store regular data like numbers or characters. Instead, it stores the address of another variable's memory location. 

```
int age = 25;        // This creates a variable 'age' in memory
int *ptr;            // This creates a pointer that can store an address
```


#### Declaring a pointer variable follows a specific syntax that tells the compiler what type of data the pointer will point to.
#### The basic syntax for declaring a pointer is: data_type *pointer_name;
<br>

```
int *ptr;        // Declares a pointer to an integer
char *ch_ptr;    // Declares a pointer to a character
float *f_ptr;    // Declares a pointer to a float
```
---

#### When you place the & operator in front of a variable name, it returns the memory address where that variable is stored.

```
int age = 25;
int *ptr;
ptr = &age;    // Store the address of 'age' in 'ptr'
```

#### In this example, &age gives us the memory address of the age variable. We then assign this address to our pointer ptr. Now ptr "points to" the age variable.

---

#### When you place the * operator in front of a pointer variable, it accesses the value stored at the memory address the pointer is holding. 
```
int age = 25;
int *ptr = &age;
printf("%d", *ptr);    // Prints 25 - the value of age
```

---
#### A NULL pointer is a pointer that doesn't point to any valid memory address. In C, NULL is typically defined as 0 or (void*)0. When you initialize a pointer to NULL, you're explicitly stating that it doesn't currently point to anything useful.

```
int *ptr = NULL;    // Initialize pointer to NULL
printf("%p", ptr);  // This will print 0 or (nil)
```