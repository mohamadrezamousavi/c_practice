#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>

int main(){
    Stack* stack = create_stack(10);
    int n;
    printf("Enter number of operation: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        char command[10];
        printf("Enter your command: push, pop, peek:");
        scanf("%s", command);
        if (strcmp(command, "push") == 0){
            int value;
            printf("Enter your value: ");
            scanf("%d", &value);
            int* p =malloc(sizeof(int));
            *p = value;
            push(stack, p);
        }
        else if (strcmp(command, "pop") == 0) {
            int* p = pop(stack);
            if (p == NULL){
                printf("Empty\n");
            }
            else{
                printf("Value is: %d\n", *p);
                free(p);
            }
        }
        else if (strcmp(command, "peek") == 0) {
            int* p = peek(stack);
               if (p == NULL){
                printf("Empty\n");
            }
            else{
                printf("Value is: %d\n", *p);
            }         
        }
    }

    while (!is_empty(stack))
    {   
        printf("%d is freed\n", *(int*)peek(stack));   
        free(pop(stack));
        printf("%d is freed\n", stack->top);
    }

    free_stack(stack);
}