#include "notifier2.h"
#include <stdlib.h>
#include <stdio.h>

static void email_notify(const char *message){
    printf("Email: %s\n", message);
}

static void sms_notify(const char *message){
    printf("sms: %s\n", message);
}

INotifier create_email_notifier(){
    INotifier notifier;
     notifier.notify = email_notify ;
    return notifier;
    
}
INotifier create_sms_notifier(){
    INotifier notifier;
     notifier.notify = sms_notify ;
    return notifier;
}