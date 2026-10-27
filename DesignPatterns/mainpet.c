#include <stdio.h>
#include "pet.h"

int main(){
    int pet_type;
    printf("Enter your pet type: ");
    scanf("%d", &pet_type);
    Pet *p = create_pet(pet_type);
    free_pet(p);
    printf("Pet Memory freed\n");
}