#ifndef COUNTER_H
#define COUNTER_H

typedef struct
{
    int value;
} Counter;

void counter_increment(Counter *c);
int counter_get(Counter *c);

#endif