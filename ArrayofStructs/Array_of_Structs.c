# include <stdio.h>

typedef struct Product {
    char name[30];
    float price;
    int stock;
} Product;

int findMostExpensive(Product myproduct[], int size){
    int index;
    float price = 0;
    for(int i = 0; i < size; i++){
        if (myproduct[i].price > price){
            price = myproduct[i].price;
            index = i;
        }
    }
    return index;

}

float calculateTotalValue(Product myproduct[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += (myproduct[i].price * myproduct[i].stock);
    }
    return sum;
}

int findLowStock(Product myproduct[], int size, int threshold){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (myproduct[i].stock < threshold)
            count++;
    }
    return count;
}

int main(){

    int size = 3;
    Product inventory[size];
    for (int i = 0; i < size; i++){
        printf("Enter Name [%d]: ", i+1);
        scanf("%29s", inventory[i].name);
        printf("Enter Price[%d]: ", i+1);
        scanf("%f", &(inventory[i].price));
        printf("Enter Stock[%d]: ", i+1);
        scanf("%d", &(inventory[i].stock));

    }
    for (int i = 0; i < size; i++){
        printf("Product[%d]: %s - Price: %.3f, stock: %d\n",i, inventory[i].name, inventory[i].price, inventory[i].stock);
    }

    int index = findMostExpensive(inventory,size);
    printf("Most Expensive Product: %s\n", inventory[index].name);
    float totalprice = calculateTotalValue(inventory, size);
    printf("Total Invetory Value: %f\n", totalprice);
    printf("Enter Threshold: ");
    int threshold;
    scanf("%d", &threshold);
    int cnt_low = 0;
    cnt_low =  findLowStock(inventory, size, threshold);
    printf("Products with low stock: %d\n", cnt_low);
    return 0;
}