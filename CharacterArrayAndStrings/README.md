## Character Arrays and Strings
#### In C, there is no built-in string data type like you might find in other programming languages. Instead, strings are represented as arrays of characters.
#### A string in C is simply a sequence of characters stored in consecutive memory locations. To create a string, you declare a character array that's large enough to hold all the characters you need, plus one extra space for a special terminating character.
```
char greeting[] = "Hello";  // Can hold 5 characters + terminator
char message[20] = "Wellcome"; // Can hold up to 19 characters + terminator
printf("%s\n", greeting);
```

---
#### every C string must end with a special character called the null terminator, written as \0.
```
char word[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
// The \0 tells C: "The string ends here"
```
---
#### The scanf function can read strings using the %s format specifier, but it comes with important limitations you need to understand.
####  scanf("%s", ...) has a critical limitation: it stops reading as soon as it encounters any whitespace character (space, tab, or newline). This means if a user types "Hello World", scanf will only capture "Hello" and leave "World" in the input buffer.
```
char word[50];
printf("Enter a word: ");
scanf("%s", word);
printf("You entered: %s\n", word);
```

---
#### C provides the strlen() function from the <string.h> library specifically for how long those strings are.
#### The strlen() function counts the number of characters in a string, stopping when it reaches the null terminator \0.
```
#include <stdio.h>
#include <string.h>

char word[] = "Hello";
int length = strlen(word);
printf("Length: %d\n", length);  // Prints: Length: 5
```

---
#### The strcpy() function takes two arguments: the destination array (where you want to copy to) and the source string (what you want to copy). It copies each character from the source to the destination, including the null terminator.
```
#include <stdio.h>
#include <string.h>

char source[] = "Hello";
char destination[20];
strcpy(destination, source);  // Copies "Hello" into destination
```
---
#### what if you want to join two strings together? This is called concatenation, and C provides the strcat() function from the <string.h> library for this purpose.

#### he strcat() function appends the contents of one string to the end of another string. It takes two arguments: the destination string (which will be modified) and the source string (which will be added to the end).
```
#include <stdio.h>
#include <string.h>

char greeting[20] = "Hello";
char name[] = " World";
strcat(greeting, name);  // greeting now contains "Hello World"
```

#### sometimes you need to concatenate a number (like an int) to a string. Since strcat() only works with character arrays, you first need to convert the number into a string. You can do this with sprintf(), which works just like printf() but writes the formatted result into a character array instead of printing it to the screen. sprintf() is part of <stdio.h>, which is already included in most C programs.
```
char summary[100] = "Total people processed: ";
int n = 3;
char numStr[20];
sprintf(numStr, "%d", n);
strcat(summary, numStr);  // summary now contains "Total people processed: 3"
```

---
#### comparing two strings character by character
```
#include <stdio.h>
#include <string.h>

char word1[] = "apple";
char word2[] = "apple";
int result = strcmp(word1, word2); 
```