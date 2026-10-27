#ifndef PRODUCT_H
#define PRODUCT_H
typedef struct{
    char name[50];
    double price;
    int quantity;
} Product;

void display_by_value(Product p);
void display_by_pointer(const Product *self);

#endif