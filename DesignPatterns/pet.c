#include <stdlib.h>
#include <stdio.h>
#include "pet.h"

typedef struct {
    Pet base;  
} Dog;

typedef struct {
    Pet base;
} Cat;

typedef struct {
    Pet base;
} Bird;

void speak_dog(void){
    printf("Woof\n");
}
void speak_cat(void){
    printf("Meow\n");
}
void speak_bird(void){
    printf("Tweet\n");
}

Dog * create_dog(void){
    Dog* dog = malloc(sizeof(Dog));
    speak_dog();
    return dog;
}
Cat * create_cat(void){
    Cat* cat = malloc(sizeof(Cat));
    speak_cat();
    return cat;
}
Bird * create_bird(void){
    Bird* bird = malloc(sizeof(Bird));
    speak_bird();
    return bird;
}

Pet* create_pet(PetType type){
    switch (type)
    {
    case PET_DOG:
        return (Pet*)create_dog();
    case PET_CAT:
        return (Pet*)create_cat(); 
    case PET_BIRD:
        return (Pet*)create_bird();                
    
    default:
        return NULL;
    }
}

void free_pet(Pet* pet){
    free(pet);
}