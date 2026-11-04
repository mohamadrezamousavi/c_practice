#include "stack.h"
#include <stdlib.h>

Stack* create_stack(int capacity){
    Stack* self = malloc(sizeof(Stack));
    if (self == NULL) return NULL;
    self->items = malloc(capacity * sizeof(void*));
    if (self->items == NULL)
    {
        free(self);
        return NULL;
    }
    self->capacity = capacity;
    self->top = 0;
    return self;
}

void push(Stack* self, void* item){
    if (self->top < self->capacity){
        self->items[self->top] = item;
        self->top++;
    }
}

void* pop(Stack* self){
    if (is_empty(self))
        return NULL;

    self->top--;

    return self->items[self->top];
  
}

void* peek(Stack* self){
    if (self->top == 0) return NULL; // Stack is empty
    return self->items[self->top - 1]; 
}

int is_empty(Stack* self){
    return self->top == 0;
}

void free_stack(Stack* self){
    free(self->items);
    free(self);
}