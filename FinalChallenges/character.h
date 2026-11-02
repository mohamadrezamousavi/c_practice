#ifndef CHARACTER_H
#define CHARACTER_H
typedef struct {
    int health;
    int damage;
} Character;

Character* create_character(int health, int damage);
void attack(Character* attacker, Character* target);
int isAlive(const Character* self);
void print_status(const Character* hero, const Character* enemy);
void free_character(Character* self);

#endif