#ifndef NOTIFIER_H
#define NOTIFIER_H

typedef void (*NotifyFunc)(const char*);

typedef struct{
    const char *name;
    NotifyFunc notify;
} Notifier;

#endif