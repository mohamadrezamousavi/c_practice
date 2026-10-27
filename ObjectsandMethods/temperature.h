#ifndef TEMPERATURE_H
#define TEMPERATURE_H
typedef struct {
    double celsius;
}Temperature;

void temp_display(const Temperature *self);
void temp_adjust(Temperature *self, double addition);
double temp_to_fahrenheit(const Temperature *self);

#endif