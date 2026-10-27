#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef int (*BinaryOp)(int,int);

typedef struct{
    BinaryOp operate;
    void (*describe) (void);
} ICalculator;
#endif