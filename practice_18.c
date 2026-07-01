// practice lesson:Student Database Using Pointers
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
    float grade;
} Student;
void inputStudents(Student *ptr, int size);
void printStudents (Student *ptr, int size);
Student *highestGrade (Student *ptr, int size);
void printHighest (Student *ptr);

int main()
{


    Student students[5];
    Student *ptr = students;
    inputStudents (ptr, 5);
    printStudents (ptr, 5);
    Student *highest =highestGrade(ptr,2);
    printHighest(highest);
    return 0;
}

void inputStudents(Student *ptr, int size)
{
for (int i = 0; i < size; i++)
{
    printf("Enter name: ");
    fgets((ptr+i)->name, sizeof((ptr+i)->name), stdin);
    (ptr+i)->name[strcspn((ptr+i)->name, "\n")] = '\0';  // strip newline

    printf("Enter age: ");
    scanf("%d", &(ptr+i)->age);

    printf("Enter grade: ");
    scanf("%f", &(ptr+i)->grade);

    while (getchar() != '\n');  // clear leftover newline from scanf before next fgets
}
}

void printStudents (Student *ptr, int size)
{   
    printf("\n%-5s %-20s %-5s %-7s\n", "Num", "Name", "Age", "Grade");

    for (int i = 0; i < size; i++)
    {
        printf("%-5d %-20s %-5d %-7.2f\n", i +1,(ptr+i) ->name,(ptr+i)->age,(ptr+i)->grade);
    }
}

void printHighest (Student *ptr)
{
    printf("\nHighest Grade Student is: %s with %.2f\n",ptr->name,ptr->grade);
}

Student *highestGrade (Student *ptr, int size)
{
    Student *highest_ptr;
    highest_ptr = ptr;
    for (int i = 1; i < size; i++)
    {
        if ((ptr+i) -> grade > highest_ptr ->grade)
           highest_ptr  = (ptr+i)  ; 
    }

    return highest_ptr;
}