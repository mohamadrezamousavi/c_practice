# Design Patterns in C
## Singleton Pattern
### Sometimes you need exactly one instance of an object throughout your entire program: a configuration manager, a logging system, or a database connection. The Singleton pattern ensures that only one instance exists and provides a global access point to it.
### In C, we implement this using a static variable inside a source file. Remember that static at file scope means the variable is private to that file and persists for the program's lifetime. Combined with a getter function, this creates our Singleton:
```
// config.c
#include "config.h"
#include <stdlib.h>

struct Config {
    int max_connections;
    int timeout;
};

static Config* instance = NULL;

Config* get_config(void) {
    if (instance == NULL) {
        instance = malloc(sizeof(Config));
        instance->max_connections = 100;
        instance->timeout = 30;
    }
    return instance;
}
```
### The magic happens in get_config(). The first call creates and initializes the instance. Every subsequent call returns the same pointer.
### The static keyword ensures instance retains its value between function calls and remains hidden from other files.
---
## Factory Pattern
### The Factory pattern centralizes object creation into a single function. Instead of scattering malloc and initialization code throughout your program, you call one function that decides what to create and returns a ready-to-use object.
### This pattern is especially powerful when combined with polymorphism. A factory can return different concrete types through a common base pointer, hiding the creation details from the caller.
```
#include <stdio.h>
#include <stdlib.h>

// 1. Base structure
typedef struct Animal {
    void (*make_sound)(void);
} Animal;

// 2. Concrete types
typedef struct {
    Animal base;
} Dog;

typedef struct {
    Animal base;
} Cat;

// 3. Animal functions
void dog_sound(void) {
    printf("Dog: Woof!\n");
}

void cat_sound(void) {
    printf("Cat: Meow!\n");
}

// 4. Constructors
Dog* create_dog(void) {
    Dog* dog = malloc(sizeof(Dog));

    if (dog == NULL)
        return NULL;

    dog->base.make_sound = dog_sound;
    return dog;
}

Cat* create_cat(void) {
    Cat* cat = malloc(sizeof(Cat));

    if (cat == NULL)
        return NULL;

    cat->base.make_sound = cat_sound;
    return cat;
}

// 5. Factory
typedef enum {
    DOG,
    CAT
} AnimalType;

Animal* create_animal(AnimalType type) {

    switch (type) {
        case DOG:
            return (Animal*)create_dog();

        case CAT:
            return (Animal*)create_cat();

        default:
            return NULL;
    }
}

// 6. Main
int main(void) {

    Animal* animal1 = create_animal(DOG);
    Animal* animal2 = create_animal(CAT);

    if (animal1 != NULL) {
        animal1->make_sound();
        free(animal1);
    }

    if (animal2 != NULL) {
        animal2->make_sound();
        free(animal2);
    }

    return 0;
}
```

---
##
### The Iterator pattern provides a way to access elements of a collection sequentially without exposing its underlying structure. Instead of giving users direct access to an array, you give them an object that knows how to step through the data one element at a time.
### An iterator typically needs two pieces of information: a reference to the collection and the current position. In C, we create a struct to hold this state:
```
typedef struct {
    int* data;      // pointer to the array
    int size;       // total number of elements
    int current;    // current position
} IntIterator;
```
### The iterator exposes two key functions. has_next() checks if there are more elements to read, and next() returns the current element and advances the position:
```
int has_next(IntIterator* it) {
    return it->current < it->size;
}

int next(IntIterator* it) {
    return it->data[it->current++];
}
```
### Using the iterator looks clean and hides the array details:
```
IntIterator it = create_iterator(numbers, 5);
while (has_next(&it)) {
    printf("%d\n", next(&it));
}
```
### The caller never needs to know that numbers is an array or how indexing works. This abstraction makes it easy to change the underlying data structure later, from an array to a linked list, for example, without changing the code that uses the iterator.