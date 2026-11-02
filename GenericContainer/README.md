# Generic Container
## Void Pointers
### A void* is C's way of saying "a pointer to something, but I'm not telling you what." It can hold the address of any data type: an int, a float, a struct, or anything else. This makes it the foundation for writing generic code in C.
### The catch is that you cannot dereference a void* directly. The compiler doesn't know how many bytes to read or how to interpret them. To use the data, you must cast it back to the correct type:
```
void print_int(void* data) {
    int* p = (int*)data;
    printf("%d\n", *p);
}

int main() {
    int x = 42;
    print_int(&x);
    return 0;
}
```
---
## Generic Wrapper
### A void* alone can store any data, but it has a critical flaw: you lose track of what type it holds. To build truly useful generic containers, we need to pair the data pointer with type information. This is where the Generic Wrapper pattern comes in.
### The idea is simple: create a struct that bundles a void* with an enum that identifies the stored type. This way, the wrapper always knows how to interpret its contents.
```
typedef enum {
    TYPE_INT,
    TYPE_STRING
} DataType;
typedef struct {
    void* data;
    DataType type;
} Wrapper;
```
### When storing data, you allocate memory for the actual value and record its type. Imagine an embedded system that receives information from different sensors:
- Temperature sensor → float
- Counter → int
- Device name → string
```
Wrapper wrap_int(int value) {
    int* p = malloc(sizeof(int));
    *p = value;
    return (Wrapper){ .data = p, .type = TYPE_INT };
}

Wrapper wrap_string(char *str){
    char* p = malloc(strlen(str) + 1);
    strcpy(p, str);
    return (Wrapper){ .data = p, .type= TYPE_STRING};
}
void print_wrapper(Wrapper* w) {
    if (w->type == TYPE_INT) {
        printf("%d\n", *(int*)w->data);
    } else if (w->type == TYPE_STRING) {
        printf("%s\n", (char*)w->data);
    }
}
```
---
## Generic Swap
### A common operation in programming is swapping two values. Normally, you'd write a separate swap function for each type: one for int, another for double, and so on. But with void* and memcpy, we can write a single function that swaps any two variables.
### The key insight is that swapping is just moving bytes around. If you know the size of the data, you can copy bytes without knowing the actual type. The function signature looks like this:
```
void generic_swap(void* a, void* b, size_t size);
```
### The size parameter tells the function how many bytes to move. Inside, we use a temporary buffer and memcpy from <string.h> to shuffle the bytes:
```
void generic_swap(void* a, void* b, size_t size) {
    char temp[size];      // temporary buffer
    memcpy(temp, a, size);  // temp = a
    memcpy(a, b, size);     // a = b
    memcpy(b, temp, size);  // b = temp
}
int main(){
int x = 5, y = 10;
generic_swap(&x, &y, sizeof(int));
// x is now 10, y is now 5
double p = 3.14, q = 2.71;
generic_swap(&p, &q, sizeof(double));
// p is now 2.71, q is now 3.14
}
```
---
## Generic Compare
### comparison function: a function you write that the generic algorithm calls whenever it needs to compare two items.
```
int compare_ints(const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    return val_a - val_b;
}
```
