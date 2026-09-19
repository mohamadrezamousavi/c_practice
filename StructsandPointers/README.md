## Structs and Pointers
#### Just as you can create pointers to basic data types like int or char, you can also create pointers that hold the address of a struct variable.
#### The syntax for declaring a pointer to a struct follows the same pattern as other pointer declarations:
```
struct StructureName *pointerName;
struct Point p1 = {10, 20};
struct Point *ptr;
ptr = &p1;
```
#### Now ptr holds the memory address of the p1 struct variable. This opens up new possibilities for working with structs, especially when passing them to functions or managing memory dynamically.

---
####  While you could use the dereference operator and dot notation together, C provides a more convenient operator specifically for this purpose: the arrow operator (->).
``` 
ptr->member
struct Point p1 = {10, 20};
struct Point *ptr = &p1;

// Using the arrow operator
printf("x = %d, y = %d\n", ptr->x, ptr->y);

// This is the same as:
printf("x = %d, y = %d\n", (*ptr).x, (*ptr).y);
```
---
#### When you pass a struct to a function as a parameter, C uses pass-by-value, which means the function receives a complete copy of the struct.
```
void functionName(struct StructureName parameterName) {
    // Function body
}

void printPoint(struct Point p) {
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}
```

---
#### When you pass a pointer to a struct instead of the struct itself, the function receives the memory address of the original struct. This approach offers two key advantages: it's more efficient (no copying) and allows the function to modify the original data.

#### The syntax for a function that accepts a pointer to a struct is:
```
void functionName(struct StructureName *ptr) {
    // Function body using ptr->member
}
```
#### Inside the function, you use the arrow operator to access and modify the struct members.
---
#### dynamic allocation: You can use malloc() to create structs on the heap, just like you would for any other data type.
```
struct Point *ptr = malloc(sizeof(struct Point));
free (ptr);
```