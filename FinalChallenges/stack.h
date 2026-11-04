#ifndef STACK_H
#define STACK_H

typedef struct{
    void** items;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity);
void push(Stack* self, void* item);
void* pop(Stack* self);
void* peek(Stack* self);
int is_empty(Stack* self);
void free_stack(Stack* self);
#endif