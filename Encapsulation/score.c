#include "score.h"
#include <stdlib.h>

struct Score {
    int value;
};

Score *create_score(int score){
    Score *s = malloc(sizeof(Score));
    s->value = score;
    return s;
}

void free_score(Score *self){
    if (self == NULL) return;
    free(self);
}

int score_get_points(const Score *self){
    return self->value;
}

void score_set_points(Score *self, int new_value){
    self->value = new_value;
}