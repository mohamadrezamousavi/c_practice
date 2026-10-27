#include <stdio.h>
#include "logger.h"

int main(void) {
    int flag;

    scanf("%d", &flag);


    Logger* logger = create_logger(flag);

    if (logger == NULL) {
        return 1;
    }

    logger->log(logger, "Starting application");
    logger->log(logger, "Shutting down");

    free_logger(logger);

    return 0;
}