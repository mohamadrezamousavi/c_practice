#ifndef TIMER_H
#define TIMER_H
typedef struct{
    int second;
} Timer;

void timer_tick(Timer *self, int a);
void timer_reset(Timer *t);

#endif