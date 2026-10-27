#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wrapper.h"

Wrapper wrap_int(int value){
    int *p = malloc(sizeof(int));
    *p = value;
    return (Wrapper){.data = p, .type = TYPE_INT}; // (Wrapper) means: create and initialize Wrapper struct
}
 
Wrapper wrap_string(char * string){
    char *c = malloc(strlen(string)+1);
    strcpy(c, string);
    return (Wrapper){.data = c, .type =TYPE_STRING}; 
}

void print_wrapper(Wrapper * w){
    if (w->type == TYPE_INT){
        printf("Data is int: %d\n", *(int*)(w->data));
    }
    else if(w->type == TYPE_STRING){
        printf("Data is string: %s\n", (char *)w->data);
    }
}

void free_wrapper(Wrapper* w){
    free(w->data);
    printf("Memory freed\n");
}

