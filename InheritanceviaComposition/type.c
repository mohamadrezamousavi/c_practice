#include <stdio.h>
#include "type.h"

void print_employee(Employee *self){
    printf("Name: %s\n", self->person.name);
    printf("Age: %d\n", self->person.age);
    printf("ID: %d\n", self->id);
}