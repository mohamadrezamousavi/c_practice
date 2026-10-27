#include <stdlib.h>
#include <string.h>
#include "movie.h"

// constructor function
Movie *create_movie(char *title, int year){
    Movie *film = malloc(sizeof(Movie));
    film->title = malloc(strlen(title)+1);
    strcpy(film->title, title);
    film->year = year;
    return film;
}

// destructor function
void free_movie(Movie *film){
    if (film == NULL) return;
    free(film->title);
    free(film);
}
