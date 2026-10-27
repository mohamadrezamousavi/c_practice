#include <stdlib.h>
#include "timer.h"

struct Timer{
    int seconds;
    int running;
};


Timer *create_timer(int seconds){
    Timer *t = malloc(sizeof(Timer)); 
    t->seconds = seconds;
    t->running = 1;

}

void free_timer(Timer *time){
    if (time == NULL) return;
    free(time);
}