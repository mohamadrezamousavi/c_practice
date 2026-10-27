#include <stdio.h>
#include "timer.h"

int main(){
    int initial_seconds,amount_to_add;
    printf("Enter Initial_Second: ");
    scanf("%d", &initial_seconds);
    printf("Enter amount to add: ");
    scanf("%d", &amount_to_add);    

    Timer time = {initial_seconds};
    timer_tick(&time, amount_to_add);
    printf("time is: %d\n", time.second);
    timer_reset(&time);
    printf("time is: %d\n", time.second);
}