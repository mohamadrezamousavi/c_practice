#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

Book *create_book(const char *title, int pages){
    Book *b = malloc(sizeof(Book));
    b->title = malloc(strlen(title) + 1);
    strcpy(b->title, title);
    b->pages = pages;
    return b;
}