## Pointers and Arrays

### Arrays and pointers in C have a special relationship that's fundamental to understanding how C works with data in memory. When you declare an array, the array name itself acts as a constant pointer to the first element of the array.

#### This means that when you have an array like int numbers[5];, the name numbers is essentially a pointer that always points to numbers[0]. You can think of the array name as a built-in pointer that you don't need to declare separately.

```
int numbers[5] = {10, 20, 30, 40, 50};
// 'numbers' points to the first element
// numbers == &numbers[0]  // These are equivalent!
```

---
### Instead of using the familiar bracket notation like array[i], you can use pointer notation to achieve the same result.
#### The key insight is that array[i] is exactly equivalent to *(array + i). When you write array + i, you're telling C to move i positions forward from the start of the array. The dereference operator * then gets the value at that location.
```
int numbers[5] = {10, 20, 30, 40, 50};
// These two lines do exactly the same thing:
printf("%d", numbers[2]);    // Prints 30
printf("%d", *(numbers + 2)); // Also prints 30
```
#### This pointer notation works because C automatically calculates the correct memory address based on the data type size. When you add 2 to an integer array pointer, C moves forward by 2 × sizeof(int) bytes, landing exactly on the third element.

---
### pointer arithmetic, which allows you to move pointers through memory using simple increment and decrement operations.
#### When you increment a pointer with ++ or decrement it with --, the pointer doesn't just move by one byte. Instead, it moves by the size of the data type it points to. For an integer pointer, ptr++ moves forward by sizeof(int) bytes, landing exactly on the next integer in memory.
```
int numbers[5] = {10, 20, 30, 40, 50};
int *ptr = numbers;    // Points to first element (10)
ptr++;                 // Now points to second element (20)
ptr++;                 // Now points to third element (30)
```
---
### pointers can also be compared using the same relational operators you use with regular variables: ==, !=, <, and >.
```
int numbers[5] = {10, 20, 30, 40, 50};
int *start = numbers;        // Points to first element
int *end = numbers + 4;      // Points to last element

if (start < end) {
    printf("start comes before end in memory");
}
```

#### Pointer comparison becomes especially powerful in loop conditions. Instead of using a counter variable, you can compare your current pointer position with a target pointer to control when the loop should stop. This creates elegant, efficient code for array traversal.