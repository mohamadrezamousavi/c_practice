#include <stdio.h>
#include "temperature.h"

int main(){
    Temperature temp = {25};
    temp_display(&temp);
    temp_adjust(&temp, 0);
    printf("temp far is: %.3f\n", temp_to_fahrenheit(&temp));
    return 0;
}