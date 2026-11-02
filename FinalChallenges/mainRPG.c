#include <stdio.h>
#include "character.h"

int main() {
    // Read input values
    int hero_health, hero_damage, enemy_health, enemy_damage;
    scanf("%d", &hero_health);
    scanf("%d", &hero_damage);
    scanf("%d", &enemy_health);
    scanf("%d", &enemy_damage);
    Character* luking = create_character(hero_health, hero_damage);
    Character* subzero = create_character(enemy_health, enemy_damage);
    while(isAlive(luking) && isAlive(subzero)){
        attack(luking, subzero);
        attack(subzero, luking);
        print_status(luking,subzero);
    }
    if (isAlive(luking) > 0 ){
        printf("LuKing win\n");
    }
    else if(isAlive(subzero) > 0){
        printf("SubZero win\n");
    }
    else {
        printf("Both died\n");
    }
}

