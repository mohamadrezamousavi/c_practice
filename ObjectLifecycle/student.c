#include "student.h"
#include <stdlib.h>
#include <string.h>

Student *create_student(char *name, int grade){
    Student *s = malloc(sizeof(Student));
    s->name = malloc(strlen(name) + 1);
    strcpy(s->name, name);
    s->grade = grade;
    return s;
}

Student *clone_student(Student *original){
    Student *copy = malloc(sizeof(Student));
    copy->name = malloc(strlen(original->name)+1);
    strcpy(copy->name, original->name);
    copy->grade = original->grade;
    return copy;
}

void free_student(Student *self){
    if (self == NULL) return;
    free(self->name);
    free(self);
}