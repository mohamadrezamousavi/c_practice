#include <stdio.h>
#include "product.h"

void display_by_value(Product p){
    printf("display by value name: %s\n", p.name);
    printf("display by value price: %f\n", p.price);
    printf("display by value price: %d\n", p.quantity);
}

void display_by_pointer(const Product *self){
    printf("display by refrence name: %s\n", self->name);
    printf("display by refrence price: %f\n", self->price);
    printf("display by refrence price: %d\n", self->quantity);    
}