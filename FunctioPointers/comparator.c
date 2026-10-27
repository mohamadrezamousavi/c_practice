#include <stdio.h>

typedef int (*Operation)(int,int);
int add(int a, int b){
    return a + b;
}
int multiply(int a, int b){
    return a * b;
}

int compute(int a, int b, Operation op){
    return op(a,b);
}

int apply_twice(int a, int b, int op_code){
    Operation operation;
    if (op_code == 1) {
        operation = add;
    } else if (op_code == 2) {
        operation = multiply;
    } else {
        return 0;
    }
    int intermediate = compute(a, b, operation);
    return compute (intermediate,b, operation);
}


