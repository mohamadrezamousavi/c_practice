#include <stdio.h>
#include "task.h"

int main(){

    Task tasks[3] = {
        {"backup", backup_task},
        {"cleanup", cleanup_task},
        {"report", report_task}
    };

    for (int i = 0; i < 3; i++){
        printf("%s  ",tasks[i].name);
        tasks[i].run();
    }
    return 0;
}