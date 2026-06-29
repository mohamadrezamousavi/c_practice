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

int main()
{


    Student students[3];
    Student *ptr = students;
    inputStudents (ptr, 3);
    printStudents (ptr, 3);
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