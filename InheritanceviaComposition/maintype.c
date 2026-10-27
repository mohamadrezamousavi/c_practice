#include <stdio.h>
#include <string.h>
#include "type.h"

int main(){
    Employee e;
    printf("Enter Name: ");
    fgets(e.person.name, 49, stdin);
    e.person.name[strcspn(e.person.name, "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &e.person.age);
    printf("Enter id: ");
    scanf("%d", &e.id);
    print_employee(&e);
    return 0;
}