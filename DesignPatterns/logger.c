#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

typedef struct {
    Logger base;
} ConsoleLogger;

typedef struct {
    Logger base;
} DummyLogger;

void console_log(Logger* logger, const char* message){
    printf("[LOG] %s\n", message);
}


void dummy_log(Logger* logger, const char* message){

}

ConsoleLogger* create_console_logger(void){
    ConsoleLogger* logger = malloc(sizeof(ConsoleLogger));
    if (logger == NULL) {
        return NULL;
    }

    logger->base.log = console_log;
    return logger;    
}

DummyLogger* create_dummy_logger(void) {
    DummyLogger* logger = malloc(sizeof(DummyLogger));

    if (logger == NULL) {
        return NULL;
    }

    logger->base.log = dummy_log;
    return logger;
}

Logger* create_logger(int flag) {
    if (flag == 1) {
        return (Logger*)create_console_logger();
    } else if (flag == 0) {
        return (Logger*)create_dummy_logger();
    }

    return NULL;
}

void free_logger(Logger* logger) {
    free(logger);
}