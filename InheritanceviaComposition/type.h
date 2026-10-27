#ifndef TYPE_H
#define TYPE_H

typedef struct{
    char name[50];
    int age;
} Person;

typedef struct{
    Person person; // first member
    int id;
} Employee;

void print_employee(Employee *self);

#endif