#include "counter.h"

void counter_increment(Counter *c){
    c->value++;
}

int counter_get(Counter *c){
    return c->value;
}