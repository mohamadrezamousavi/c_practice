#include "stringbuilder.h"
#include <string.h>

StringBuilder* create_string(){
    StringBuilder* s = malloc(sizeof(StringBuilder));
    s->total_capacity = 16;
    s->current_length = 0; 
    s->buffer = malloc(s->total_capacity);       
    s->buffer[0] = '\0';
    return s;
}

void append_text(StringBuilder* self, char* text){
    size_t text_length = strlen(text);
    size_t new_length = self->current_length + text_length;
    while(new_length + 1 > self->total_capacity){

        self->total_capacity *= 2;
        char* temp = realloc(self->buffer, self->total_capacity);
        self->buffer = temp;

    }
    strcat(self->buffer, " ");
    strcat(self->buffer, text);
}

char* get_string(StringBuilder* self){
    return self->buffer;
}
void free_stringbuilder(StringBuilder* self){
    free(self->buffer);
    free(self);
}