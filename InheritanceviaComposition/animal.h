#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct {
    int legs;
} Animal;

typedef struct{
    Animal animal;
    char name[50];
} Dogs;

void print_animal(Animal *self);


#endif