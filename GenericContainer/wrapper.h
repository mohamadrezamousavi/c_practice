#ifndef WRAPPER_H
#define WRAPPER_H
typedef enum{
    TYPE_INT,
    TYPE_STRING
} DataType;

typedef struct{
    void* data;
    DataType type;
} Wrapper;

Wrapper wrap_int(int value);
Wrapper wrap_string(char *string);
void print_wrapper(Wrapper * w);
void free_wrapper(Wrapper* w);


#endif