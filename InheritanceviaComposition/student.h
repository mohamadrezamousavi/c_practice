#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    char name[50];
    int age;
} Person;

typedef struct{
    Person person;
    int grade;
} Student;

void set_person_age(Student *self, int new_age);
void print_student(Student *self);

#endif