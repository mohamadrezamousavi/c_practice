#include "timer.h"

void timer_tick(Timer *self, int a){
    self->second += a;
}
void timer_reset(Timer *self){
    self->second = 0;
}