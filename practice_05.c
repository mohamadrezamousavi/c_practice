// practice lesson: using switch and getchar()
// Class grades report of teacher
// Grades : A, B, C, D, E
#include<stdio.h>
#define True -1

int main()
{
    char grade;
    int a, b, c, d, e;
    int i = 0;
    while((grade = getchar()) != 'f')
    {
        
        switch (grade)
        {
        case 'a':
        case 'A':
            a++;
            break; 
        case 'b':
        case 'B':
            b++;
            break;   
        case 'c':
        case 'C':
            c++;                      
            break; 
        case 'd':
        case 'D':
            d++;                      
            break; 
        case 'e':
        case 'E':
            e++;                      
            break;                                  
        case '\n':
            /* code */
            break;
        
        default:
            printf("Incorrect input. Please enter from letters set {A, B, C, D, E}.\n");
            break;
        }
        
        
    }
    int all = a+b+c+d+e;
    printf("\nNumber of students: %d\n", all);
    printf("Number of A grade: %d\n", a);
    printf("Number of B grade: %d\n", b);
    printf("Number of C grade: %d\n", c);
    printf("Number of D grade: %d\n", d);
    printf("Number of E grade: %d\n\n", e);    
    return 0;
}