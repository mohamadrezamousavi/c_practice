#include <stdio.h>

void print_value(void* data, int flag){
    if (flag == 0){
        int *p = (int *) data;
        printf("%d\n", *p);
    }
    else if (flag == 1){
        float *p = (float *) data;
        printf("%.2f\n", *p);
    }
}

int main(){
    int flag;
    scanf("%d", &flag);

    if (flag == 0){
        int value;
        scanf("%d", &value);
        print_value(&value, flag);
    }
    else if (flag == 1){
        float value;
        scanf("%f", &value);
        print_value(&value, flag);
    }

    
    return 0;
}