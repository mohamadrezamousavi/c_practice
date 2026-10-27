#ifndef SCORE_H
#define SCORE_H

typedef struct Score Score;

Score *create_score(int score);
void free_score(Score *self);
int score_get_points(const Score *self);
void score_set_points(Score *self, int new_value);
#endif