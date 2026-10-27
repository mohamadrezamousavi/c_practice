#include <stdio.h>

int add(int a, int b){
    return (a + b);
}
int subtract(int a, int b){
    return (a - b);
}

int main(){
    int a,b,op1,op2;
    int (*calc)(int, int);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &op1);
    scanf("%d", &op2);
    printf("a: %d\n",a);
    printf("b: %d\n",b);
    printf("op1: %d\n",op1);
    printf("op2: %d\n",op2);

    if (op1 == 1){
        calc = add;
        printf("operation add\n");
    }
    else if (op1 == 2){
        calc = subtract;
        printf("operation subtract\n");
    }
    printf("Result: %d\n", calc(a,b));
    if (op2 == 1){
        calc = add;
        printf("operation add\n");
    }
    else if (op2 == 2){
        calc = subtract;
        printf("operation subtract\n");
    }

    printf("Result: %d\n", (*calc)(a,b));

}