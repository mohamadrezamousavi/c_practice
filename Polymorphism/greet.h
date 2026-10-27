#ifndef GREET_H
#define GREET_H

typedef void (*GreetFunc)(const char*);
typedef struct{
    const char *language;
    GreetFunc greet;
} Greeter;

void greet_english(const char *name);
void greet_spanish(const char *name);

#endif