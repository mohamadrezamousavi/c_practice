#include "iterator.h"

IntIterator create_iterator(int *data, int size){
    IntIterator it;
    it.current = 0;
    it.size = size;
    it.data = data;
}

int has_next(IntIterator* it){
    return it->current < it->size;
}
int next(IntIterator* it){
    return it->data[it->current++];
}