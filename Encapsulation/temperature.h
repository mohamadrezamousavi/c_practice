#ifndef TEMPERATURE_H
#define TEMPERATURE_H

typedef struct Temperature Temperature;

Temperature *create_temp(int degree);
void free_temp(Temperature *self);
int temp_get_degrees(const Temperature *self);
int temp_set_degrees(Temperature *self, int new_value);
#endif