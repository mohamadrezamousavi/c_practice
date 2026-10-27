#include <stdio.h>
#include <string.h>
#include "animal.h"

int main(){
    Dogs dog;
    printf("Enter Leg number: ");
    scanf("%d", &dog.animal.legs);
    getchar();
    printf("Enter Dog's Name: ");
    fgets(dog.name, 49, stdin);
    dog.name[strcspn(dog.name, "\n")] = '\0';
    printf("Dog name: %s\n", dog.name);
    print_animal((Animal *)&dog);
    return 0;
}