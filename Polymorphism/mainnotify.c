
#include <stdio.h>
#include <string.h>
#include "notifier.h"

void alert_notify(const char *message) {
    printf("[ALERT] %s\n", message);
}

void info_notify(const char *message) {
    printf("[INFO] %s\n", message);
}

int main(void) {
    int type;
    char message[256];

    scanf("%d", &type);
    getchar();  // Consume the newline after the number
    fgets(message, sizeof(message), stdin);

    // Remove the newline added by fgets
    message[strcspn(message, "\n")] = '\0';

    Notifier n;

    if (type == 1) {
        n.name = "ALERT";
        n.notify = alert_notify;
    } else if (type == 2) {
        n.name = "INFO";
        n.notify = info_notify;
    } else {
        return 1;
    }

    n.notify(message);

    return 0;
}
