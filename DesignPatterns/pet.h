#ifndef PET_H
#define PET_H

typedef enum{
    PET_DOG,
    PET_CAT,
    PET_BIRD
} PetType;


typedef struct Pet Pet;

typedef void (*operation)(const Pet*);

struct Pet {
    operation speak;
};

Pet* create_pet(PetType type);
void free_pet(Pet* pet);

#endif