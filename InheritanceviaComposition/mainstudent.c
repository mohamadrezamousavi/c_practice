#include <stdio.h>
#include <string.h>
#include "student.h"

int main(){
    Student s;
    printf("Enter Name: ");
    fgets(s.person.name, 49, stdin);
    s.person.name[strcspn(s.person.name, "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &s.person.age);
    printf("Enter Grade: ");
    scanf("%d", &s.grade);    
    int new_age;
    printf("Enter New Age: ");
    scanf("%d", &new_age);  
    set_person_age(&s,new_age);
    print_student(&s);
    return 0;    
}