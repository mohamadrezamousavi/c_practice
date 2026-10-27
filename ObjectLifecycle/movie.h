#ifndef MOVIE_H
#define MOVIE_H
typedef struct{
    char *title;
    int year;
} Movie;

Movie *create_movie(char *title, int age);
void free_movie(Movie *film);

#endif