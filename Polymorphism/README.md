# Polymorphism
## Function Pointers in Structs
### The next step toward polymorphism is embedding a function pointer directly inside a struct, giving the struct its own behavior.
```
typedef void (*PrintFunc)(const char*);

typedef struct {
    const char* name;
    PrintFunc print;  // Function pointer as a member
} Printer;
```
### The Printer struct now has two members: data (name) and behavior (print).
```
void loud_print(const char* msg) {
    printf("!!! %s !!!\n", msg);
}

int main() {
    Printer p;
    p.name = "Alert";
    p.print = loud_print;
    
    p.print("Hello");  // Output: !!! Hello !!!
    return 0;
}
```
---
## Simulating Methods
### The real power comes when you assign different functions to different instances of the same struct type. This is how we simulate methods with varying behavior.
```
typedef void (*ActionFunc)(void);

typedef struct {
    const char* name;
    ActionFunc execute;
} Action;

void say_hello(void) {
    printf("Hello!\n");
}

void say_goodbye(void) {
    printf("Goodbye!\n");
}

int main() {
    Action greet = { "Greet", say_hello };
    Action farewell = { "Farewell", say_goodbye };
    
    greet.execute();    // Output: Hello!
    farewell.execute(); // Output: Goodbye!
    return 0;
}
```
## The Interface Concept
### if a struct contain only function pointers, we call it interface
### An interface defines what operations are available without specifying how they work.
```
#include <stdio.h>

typedef void (*TurnOnFunc)(void);

typedef struct {
    TurnOnFunc turn_on;
} ISwitch;

void turn_on_light(void) {
    printf("Light is ON\n");
}

void turn_on_fan(void) {
    printf("Fan is spinning\n");
}

void activate(ISwitch* device) {
    device->turn_on();
}

int main(void) {
    ISwitch light = {turn_on_light};
    ISwitch fan = {turn_on_fan};

    activate(&light);
    activate(&fan);

    return 0;
}
```
---
## Implementing Interfaces
### Now that you understand what an interface is, a struct containing only function pointers, it's time to create concrete implementations that fulfill that contract.
```
typedef void (*LogFunc)(const char* message);

typedef struct {
    LogFunc log;
} ILogger;

void console_log(const char* message) {
    printf("[CONSOLE] %s\n", message);
}

void file_log(const char* message) {
    printf("[FILE] %s\n", message);  // Simulating file output
}

ILogger create_console_logger() {
    ILogger logger = { console_log };
    return logger;
}

ILogger create_file_logger() {
    ILogger logger = { file_log };
    return logger;
}

void do_work(ILogger* logger) {
    logger->log("Starting work...");
    logger->log("Work complete!");
}

int main() {
    ILogger console = create_console_logger();
    ILogger file = create_file_logger();
    
    do_work(&console);  // Uses console_log
    do_work(&file);     // Uses file_log
    return 0;
}
```