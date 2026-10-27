#ifndef SPEAK_H
#define SPEAK_H

typedef void (*Speakfunction)(void);
typedef struct {
    const char *name;
    Speakfunction spk_func;
} Speak_Struct;

#endif