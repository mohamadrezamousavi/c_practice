#include <stdio.h>
#include "student.h"
#include <string.h>

int main(){
    char name[100];
    int grade;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter grade: ");
    scanf("%d", &grade);
    Student *stu1 = create_student(name, grade);
    Student *stu1_cpy = clone_student(stu1);
    printf("Original: %s, %d\n", stu1->name, stu1->grade);
    printf("Clone: %s, %d\n", stu1_cpy->name, stu1_cpy->grade);
    free_student(stu1);
    free_student(stu1_cpy);
    printf("both objects freed\n");
    

    return 0;
}