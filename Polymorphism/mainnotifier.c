#include <stdio.h>
#include <string.h>
#include "notifier2.h"

int main(){
    INotifier notifier;
    int type;
    char message[100];
    scanf("%d", &type);
    getchar();
    fgets(message, 99, stdin);
    message[strcspn(message, "\n")] = '\0';
    if (type == 1) {
        notifier = create_email_notifier();
    } else if (type == 2) {
        notifier = create_sms_notifier();
    } else {
        return 1;
    }

    notifier.notify(message);
    return 0;
}