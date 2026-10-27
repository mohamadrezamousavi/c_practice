#ifndef TASK_H
#define TASK_H

typedef void (*TaskFunc)(void);
typedef struct{
    char *name;
    TaskFunc run;
} Task;

void backup_task(void);
void cleanup_task(void);
void report_task(void);
#endif