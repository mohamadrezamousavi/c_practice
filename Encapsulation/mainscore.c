#include <stdio.h>
#include "score.h"

int main(){
    Score *s = create_score(12);
    printf("score is: %d\n", score_get_points(s));
    score_set_points(s,15);
    printf("score is: %d\n", score_get_points(s));
    free_score(s);
    return 0;
}