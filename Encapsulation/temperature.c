#include <stdlib.h>
#include "temperature.h"

struct Temperature{
    int degree;
};

Temperature *create_temp(int degree){
    Temperature *temp = malloc(sizeof(Temperature));
    temp->degree = degree;
    return temp;
}

void free_temp(Temperature *self){
    if (self == NULL) return;
    free(self);
}

int temp_get_degrees(const Temperature *self){
    return self->degree;
}

int temp_set_degrees(Temperature *self, int new_value){
    if (new_value >= -50 && new_value <= 150){
        self->degree = new_value;
        return 1;
    }
    else{
        return 0;
    }

}