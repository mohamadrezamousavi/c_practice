#ifndef LOGGER_H
#define LOGGER_H


typedef struct Logger Logger;
typedef void (*operation)(Logger*, const char*);

struct Logger {
    operation log;
};

Logger* create_logger(int flag);
void free_logger(Logger* l);

#endif