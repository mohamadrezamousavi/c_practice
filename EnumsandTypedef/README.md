## Enums and Typedef
#### When writing C programs, you often need to work with sets of related constant values. For example, you might need to represent days of the week, months of the year, or different states in a program. Instead of using raw numbers like 0, 1, 2, you can use enum to create meaningful names for these constants.

#### An enumerated type, or enum, allows you to define a group of named integer constants. This makes your code much more readable and easier to maintain. Here's the basic syntax:
```
enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum DayOfWeek today;
today = MONDAY;  // assigns 0 to today
```
---
#### One of the most powerful combinations in C programming is using enum values with switch statements.
#### his pairing creates exceptionally readable and maintainable control flow logic that clearly expresses your program's decision-making process. When you use enum constants as cases in a switch statement, the code becomes self-documenting.
```
switch (day) {
    case MONDAY:
    case TUESDAY:
    case WEDNESDAY:
    case THURSDAY:
    case FRIDAY:
        printf("It's a weekday\n");
        break;
    case SATURDAY:
    case SUNDAY:
        printf("It's a weekend\n");
        break;
}
```
---
####  The typedef keyword provides a solution by allowing you to create new names for existing data types. Think of typedef as creating an alias or nickname for a data type. The basic syntax is straightforward
```
typedef existing_type new_name;
typedef int Integer;
```
---
#### One of the most practical applications of typedef is creating aliases for struct types. This eliminates the need to repeatedly write the struct keyword every time you declare a variable of that type, making your code cleaner and more readable.

```
typedef struct Point {
    int x;
    int y;
} Point;

Point myPoint = {12, 14};

typedef enum Weather{
    sunny,
    cloudy,
    rainy,
    snowy
} Weather;

Weather newYorkWeather;
```
