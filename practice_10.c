// practice lesson: Array
// string array, fgets()

#include <stdio.h>

int main()
{
    char Name[20];
    printf("Enter your name: ");
    fgets(Name,sizeof(Name),stdin);
    printf("Your name is: %s\n",Name);
    return 0;
}