#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H
#include <stdlib.h>

typedef struct{
    char* buffer;
    size_t current_length;
    size_t total_capacity;
} StringBuilder;

StringBuilder* create_string(void);
void append_text(StringBuilder* self, char* text);
char* get_string(StringBuilder* self);
void free_stringbuilder(StringBuilder* string);


#endif