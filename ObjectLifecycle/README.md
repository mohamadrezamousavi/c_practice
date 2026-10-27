# Object Life Cycle
## Constructor Pattern
### special functions that automatically allocate memory and initialize fields. C has no such feature, but we can simulate it with a simple pattern: a create_ function.
### A constructor function in C typically does three things: allocates memory with malloc, initializes all fields to proper values, and returns a pointer to the new object:
```
typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->age = age;
    return p;
}
```
### The function returns a pointer because the object lives on the heap, not the stack. This means it persists after the function returns and can be passed around freely. The caller uses it like this:
```
Person *alice = create_person("Alice", 30);
printf("%s is %d years old\n", alice->name, alice->age);

```
### Notice how the constructor handles all the messy details: allocating the struct, allocating space for the string, and copying the data. The caller just provides the initial values and receives a ready-to-use object. This encapsulates the creation logic in one place, making your code cleaner and less error-prone.

## Destructor Pattern
### Every object created with malloc must eventually be freed. Just as we wrote a create_ function to handle allocation, we write a free_ function to handle cleanup. This is the destructor pattern.
### The key insight is that freeing must happen in reverse order of allocation. If your constructor allocated internal members first and then the struct itself, your destructor must free the struct's members first, then the struct:
```
typedef struct {
    char *name;
    int age;
} Person;

void free_person(Person *p) {
    if (p == NULL) return;  // Safety check
    free(p->name);          // Free internal member first
    free(p);                // Then free the struct itself
}
```
###  After freeing the internal name string, we free the struct itself. If we freed p first, we'd lose access to p->name and cause a memory leak.

### Using the destructor is straightforward:
```
Person *alice = create_person("Alice", 30);
// ... use alice ...
free_person(alice);  // Clean up when done
```
### This pattern ensures all memory is properly released. Without it, every object you create would leak memory until your program runs out.

## Stack Initialization
### Not every object needs to live on the heap. When a struct is small and has a short lifespan, allocating it on the stack is simpler and faster: no malloc, no free, no risk of memory leaks.
### Instead of returning a pointer, a factory function can return the struct by value. The entire struct gets copied to the caller:
```
typedef struct {
    int x;
    int y;
} Point;

Point create_point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
```
### The caller receives a fully initialized copy:
```
Point origin = create_point(0, 0);
Point cursor = create_point(100, 50);
printf("Cursor: (%d, %d)\n", cursor.x, cursor.y);
```
## Deep Copy
### A deep copy allocates new memory for pointer members and copies the actual data:
```
Person *clone_person(const Person *original) {
    Person *copy = malloc(sizeof(Person));
    copy->name = malloc(strlen(original->name) + 1);
    strcpy(copy->name, original->name);
    copy->age = original->age;
    return copy;
}
```
### Now each object owns its own string. You can modify or free one without affecting the other. The pattern is straightforward: for each pointer member, allocate fresh memory and copy the contents, not just the address.