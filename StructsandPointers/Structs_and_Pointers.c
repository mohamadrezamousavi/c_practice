/*
This challenge combines all the key concepts from the chapter:
defining structs, dynamic memory allocation with malloc(), 
checking for allocation failure, passing struct pointers to functions,
using the arrow operator to access and modify struct members,
and proper memory cleanup with free()
The functions demonstrate how pointers allow direct modification of the original struct data.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
    int id;
    char name[50];
    char department[30];
    float salary;
    int yearsofservice;
};

void fillEmployeeData (struct Employee *ptr);
void displayEmployee (struct Employee *ptr);
void promoteEmployee (struct Employee *ptr);

int main (){

    struct Employee *empPtr;

    empPtr = malloc(sizeof(struct Employee));
    if (empPtr == NULL)
        printf("Memory Allocation Failed\n");
    else
        printf("Memory Allocation Successful\n");

    fillEmployeeData(empPtr);
    printf("Initial Employee Data:\n\n");
    displayEmployee(empPtr);
    promoteEmployee(empPtr);
    printf("After Promotion:\n");
    displayEmployee(empPtr);
    free(empPtr);
    printf("Memory Freed Successfuly\n\n");

    return 0;
}

void fillEmployeeData (struct Employee *ptr)
{
    printf("Enter ID: ");
    scanf("%d", &(ptr->id));
    printf("Enter Name: ");
    scanf("%49s", ptr->name);
    printf("Enter Deparment: ");
    scanf("%29s", ptr->department);
    printf("Enter Salary: ");
    scanf("%f", &(ptr->salary));
    printf("Enter YearsofService: ");
    scanf("%d", &(ptr->yearsofservice));

    float bonus;
    if (ptr->yearsofservice >= 5)
        bonus = 0.1 * ptr->salary;
    else
        bonus = 0.05 * ptr->salary;

    ptr->salary += bonus;

}

void displayEmployee (struct Employee *ptr)
{
    printf("Employee Information:\n");
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Department: %s\n", ptr->department);
    printf("Salary: %.3f\n", ptr->salary);
    printf("YearsofServices: %d\n\n",ptr->yearsofservice);

}

void promoteEmployee (struct Employee *ptr)
{
    ptr->salary += (0.15 * ptr->salary);
    ptr->yearsofservice += 1;
    printf("Employee Promoted Successfuly\n");
}