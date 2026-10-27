#include <stdio.h>
#include <string.h>
#include "movie.h"

int main(){
    char title[100];
    int year;
    printf("Enter Title: ");
    fgets(title, 100,stdin);
    title[strcspn(title,"\n")] = '\0';
    printf("Enter year: ");
    scanf("%d", &year);
    Movie *film = create_movie(title,year);
    printf("Object created\n");
    printf("Movie Title: %s\n", film->title);
    printf("Movie Year: %d\n", film->year);
    free_movie(film);
    printf("memory freed\n");

    return 0;
}