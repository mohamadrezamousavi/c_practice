#include <stdio.h>
#include "calculator.h"

int add(int a, int b){
    return a + b;
}

int multiply (int a, int b){
    return a * b;
}

void describe_add(){
    printf("Addition\n");
}
void describe_multiply(){
    printf("Multiplication\n");
}

int main(){
    ICalculator IC;
    int a,b,op;
    scanf("%d %d %d", &a, &b, &op);
    if (op == 1){
        IC.operate = add;
        IC.describe = describe_add;
    }
    if (op == 2){
        IC.operate = multiply;
        IC.describe = describe_multiply;
    }
    IC.describe();
    printf("Result: %d\n", IC.operate(a,b));


    return 0;
}