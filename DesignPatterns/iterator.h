#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct{
    int *data;
    int size;
    int current;
} IntIterator;

IntIterator create_iterator(int *data, int size);
int has_next(IntIterator * it);
int next(IntIterator * it);

#endif