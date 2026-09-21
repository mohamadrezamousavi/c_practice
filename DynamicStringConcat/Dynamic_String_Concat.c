# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char *concatenateStrings (char *string1, char *string2){

    char *ptr;
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);
    size_t totalLen = len1 + len2 + 1; // 1 for '\0' 
    printf("Sum Len: %zu\n", totalLen);
    ptr = malloc(totalLen);

    strcpy(ptr, string1);
    strcat(ptr, string2);

    return ptr;
}

char *processText(char *string1, char *string2, char *separator){


    char *ptr1;
    char *ptr2;
    ptr1 = concatenateStrings(string1, separator);
    ptr2 = concatenateStrings(ptr1, string2);
    free(ptr1);

    return ptr2;
}



int main (){
    char firstWord[50];
    char secondWord[50];
    char connector[50];
    char *ptr;
    printf("First Word: ");
    scanf("%s", firstWord);
    printf("Second Word: ");
    scanf("%s", secondWord);
    printf("Connector: ");
    scanf("%s", connector);   

    ptr = processText(firstWord, secondWord, connector);
    if (ptr == NULL)
        printf("Memory Allocation Failed!\n");
    else 
        printf("Memory Allocation Successful\n");
    
    size_t length = strlen(ptr);
    printf("Length of String: %zu\n", length);
    printf("String: %s\n", ptr);
    free(ptr);
    
    return 0;
}