#include <stdio.h>
#include "animal.h"

void print_animal(Animal *self){
    printf("Animal Legs: %d\n", self->legs);
}