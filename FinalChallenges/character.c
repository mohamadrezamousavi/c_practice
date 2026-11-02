#include <stdio.h>
#include <stdlib.h>
#include "character.h"

Character* create_character(int health, int damage){
    Character* hero = malloc(sizeof(Character));
    hero->health = health;
    hero->damage = damage;
    return hero;
}
void attack(Character* attacker, Character* target){
    target->health -= attacker->damage;
}

int isAlive(const Character* self){
    if (self->health > 0) return 1;
    else return 0; 
}

void print_status(const Character* hero, const Character* enemy){
    printf("Health Hero: %d Health Enemy: %d\n", hero->health, enemy->health);
}

void free_character(Character* self){
    free(self);
}