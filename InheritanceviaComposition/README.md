# Inheritance via Composition
## Struct Embedding
### In object-oriented languages like C++ or Java, inheritance allows a class to acquire properties from a parent class. C doesn't have built-in inheritance, but we can simulate it using a technique called composition: placing one struct inside another.
### The idea is simple: if a Child needs all the properties of a Parent, we embed the Parent struct as a member of Child.
```
typedef struct {
    int id;
    char name[50];
} Parent;

typedef struct {
    Parent parent;  // Embedded struct
    int grade;
} Child;
```
### Here, Child contains everything Parent has, plus its own grade field. This is composition: the child "has a" parent rather than "is a" parent, but the effect is similar to inheritance.
```
Child c;
c.parent.id = 101;
c.parent.name[0] = 'A';
c.grade = 5;
```
---
## The First Member Rule
### When you embed a struct as the first member of another struct, something powerful happens: the memory address of the outer struct is identical to the memory address of its first member.
```
Child c;
Child* child_ptr = &c;
Parent* parent_ptr = (Parent*)child_ptr;  // Safe cast!
```
### Both pointers hold the same address. This allows you to pass a Child* (a pointer to Child) to any function expecting a Parent* (a pointer to Parent):
```
void print_id(Parent* p) {
    printf("ID: %d\n", p->id);
}

// In main:
Child c;
c.parent.id = 42;
print_id((Parent*)&c);  // Works perfectly
```
### This technique is the foundation of inheritance in C. A function written for the base type can operate on any derived type, as long as the base is embedded first. The cast is safe because the memory layouts align perfectly.
---
## Accessing Parent Members
### When a function receives a Child struct (or a pointer to one), accessing the parent's members requires navigating through the embedded struct. The syntax depends on whether you're working with a value or a pointer.
### With a pointer to Child:
```
void update_score(Child* c, int new_score) {
    c->parent.score = new_score;  // Arrow then dot
}

void print_info(Child* c) {
    printf("ID: %d, Score: %d\n", c->parent.id, c->parent.score);
}

```
### With a value (passed by copy):
```
void show_id(Child c) {
    printf("ID: %d\n", c.parent.id);  // Dot then dot
}
```

## Upcasting
### Upcasting is the act of treating a specific (derived) type as its more general (base) type.
```
typedef struct {
    int speed;
} Vehicle;

typedef struct {
    Vehicle vehicle;  // Base as first member
    int doors;
} Car;

void accelerate(Vehicle* v, int amount) {
    v->speed += amount;
}

Car my_car = {{0}, 4};  // speed=0, doors=4
accelerate((Vehicle*)&my_car, 50); 
printf("Speed: %d\n", my_car.vehicle.speed);  // Output: 50
```
### This is upcasting: we're moving "up" from a specific type to a general one. The function accelerate doesn't know it's working with a Car; it only sees a Vehicle
