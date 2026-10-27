#include <stdio.h>
#include <string.h>
#include "book.h"

int main(){
    char title[100];
    int pages;
    printf("Enter Book Title: ");
    fgets(title,100,stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Enter Pages: ");
    scanf("%d", &pages);
    Book *b = create_book(title,pages);
    printf("book title: %s\n", b->title);
    printf("memory size title: %zu\n", strlen(b->title)+1);
    printf("book pages: %d\n", b->pages);
    return 0;
}