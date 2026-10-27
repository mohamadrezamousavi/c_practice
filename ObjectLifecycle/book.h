#ifndef BOOK_H
#define BOOK_H
typedef struct{
    char *title;
    int pages;
} Book;

Book *create_book(const char *title, int pages);

#endif