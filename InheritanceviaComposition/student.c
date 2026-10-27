#include <stdio.h>
#include "student.h"

void set_person_age(Student *self, int new_age){
    self->person.age = new_age;
}

void print_student(Student *self){
    printf("Student Name: %s\n",self->person.name);
    printf("Student Age: %d\n",self->person.age);
    printf("Student Grade: %d\n",self->grade);
}