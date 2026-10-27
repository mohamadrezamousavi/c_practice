## Objects and Methods in C
### Structs as Objects
#### In object-oriented languages, an object is an entity that bundles data (state) with functions that operate on that data (methods)
#### C doesn't have built-in objects, but we can achieve the same concept using structs and functions.
#### Think of a struct as the "data" part of an object. It holds the state: the values that define what the object currently is:
```
typedef struct {
    int value;
} Counter;

```
#### To give it behavior, we write functions that accept the struct as a parameter:

```
void counter_increment(Counter *c) {
    c->value++;
}

int counter_get(Counter *c) {
    return c->value;
}

```
#### These functions act like methods. They operate specifically on Counter data. By passing the struct to functions, we're simulating what other languages do automatically when you call counter.increment().

```
int main() {
    Counter my_counter = {0};
    counter_increment(&my_counter);
    printf("%d\n", counter_get(&my_counter)); // Prints: 1
    return 0;
}

```
#### The naming convention typename_action (like counter_increment) helps organize your code and makes it clear which struct a function belongs to. This pattern is the foundation of object-oriented programming in C.
---

### The 'Self' Pointer
#### In object-oriented languages like Python or Java, when you call object.method(), the language automatically passes the object itself to the method. In C, we must do this manually by passing a pointer to the struct as the first argument.
#### This pointer is conventionally named self (borrowed from Python) or this (from C++). It gives the function access to the struct's data so it can read or modify it:
```
typedef struct {
    int health;
} Player;

void player_take_damage(Player *self, int amount) {
    self->health -= amount;
}

```
#### The self pointer is what makes the function act like a method. It knows which player to modify. Without it, the function would have no way to access the specific struct instance. Using a pointer (rather than passing the struct directly) is essential for modification. If you passed the struct by value, the function would receive a copy, and any changes would be lost when the function returns. The pointer ensures changes persist in the original struct.

```
Player hero = {100};
player_take_damage(&hero, 25);
// hero.health is now 75
```
---
### Const Correctness
#### By marking a pointer parameter as const, you're promising that the function won't modify the data it points to when it's needed
```
typedef struct {
    int x;
    int y;
} Point;

// This function can only READ the point
void point_print(const Point *self) {
    printf("(%d, %d)\n", self->x, self->y);
    // self->x = 10;  // ERROR: cannot modify through const pointer
}

// This function can MODIFY the point
void point_move(Point *self, int dx, int dy) {
    self->x += dx;
    self->y += dy;
}
```
#### This is called const correctness: using const wherever modification isn't needed.
---
### Pointer vs Value
#### Passing by value creates a complete copy of the struct on the stack. imagine a struct with hundreds of bytes: every function call copies all that data:
```
typedef struct {
    char name[100];
    int scores[50];
    double average;
} Student;

// By value: copies ~308 bytes every call
void print_by_value(Student s) {
    printf("%s: %.2f\n", s.name, s.average);
}

// By pointer: copies only 8 bytes (the address)
void print_by_pointer(const Student *s) {
    printf("%s: %.2f\n", s->name, s->average);
}
```
#### The syntax differs too. With a value parameter, you use the dot operator (s.name). With a pointer, you use the arrow operator (s->name).
#### The pointer version is more efficient because it only passes a memory address, typically 8 bytes regardless of struct size.
---
### Helper Methods
#### Another important category: functions that compute derived values from struct members without changing anything.
```
typedef struct {
    double width;
    double height;
} Rectangle;

double rectangle_area(const Rectangle *self) {
    return self->width * self->height;
}

double rectangle_perimeter(const Rectangle *self) {
    return 2 * (self->width + self->height);
}
```
#### These are helper methods
