#ifndef NOTIFIER2_H
#define NOTIFIER2_H

typedef void (*NotifyFunc)(const char*);
typedef struct{
    NotifyFunc notify;
} INotifier;

INotifier create_email_notifier();

INotifier create_sms_notifier();

#endif