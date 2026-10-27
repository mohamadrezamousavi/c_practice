#include <stdio.h>
#include <string.h>
#include "product.h"

int main(){
    Product p;
    printf("Enter name: ");
    fgets(p.name,50,stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("Enter Price: ");
    scanf("%lf", &(p.price));
    printf("Enter quantity: ");
    scanf("%d", &(p.quantity));    
    display_by_value(p);
    display_by_pointer(&p);

    return 0;
}