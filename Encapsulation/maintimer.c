#include <stdio.h>
#include "timer.h"

int main(){
    Timer *time =  create_timer(12);
    printf("Timer constructed\n");
    free_timer(time);
    printf("freed\n");
    
}