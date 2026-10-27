#include <stdio.h>
#include <string.h>
#include "greet.h"

int main(){
    Greeter english;
    Greeter spanish;
    char name[50];
    fgets(name, 49, stdin);
    name[strcspn(name, "\n")] = '\0';
    english.language = "English";
    spanish.language = "Spanish";
    english.greet = greet_english;
    spanish.greet = greet_spanish;

    english.greet(name);
    spanish.greet(name);
    return 0;
}