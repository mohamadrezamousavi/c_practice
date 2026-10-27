#ifndef STUDENT_H
#define STUDENT_H
typedef struct {
    char *name;
    int grade;
} Student;

Student *create_student(char *name, int grade);
Student *clone_student(Student *original);
void free_student(Student *self);

#endif