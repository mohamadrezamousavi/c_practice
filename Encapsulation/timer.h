#ifndef TIMER_H
#define TIMER_H

typedef struct Timer Timer;

Timer *create_timer(int seconds);
void free_timer(Timer *time);

#endif