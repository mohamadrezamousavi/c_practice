#include <stdio.h>
#include "temperature.h"

void temp_display(const Temperature *self){
    printf("Temp celsius is : %.3f\n",self->celsius);
}
void temp_adjust(Temperature *self, double addition){
    self->celsius += addition;
}

double temp_to_fahrenheit(const Temperature *self){
    return (self->celsius * 9.0 / 5.0 + 32.0);
}
