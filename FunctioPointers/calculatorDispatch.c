#include <stdio.h>

typedef int (*Operation)(int,int);

int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a/b;
}
int main(){
    int a,b,op_code;
    Operation op[4] = {add, sub, mul, divide};
    scanf("%d %d %d", &a, &b, &op_code);
    int result= op[op_code](a,b);
    printf("Result: %d\n", result);
    return 0;
}