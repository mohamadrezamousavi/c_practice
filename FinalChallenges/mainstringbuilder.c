#include <stdio.h>
#include "stringbuilder.h"
#include <string.h>

int main(){
    int n;
    printf("Enter how many string want to append: ");
    scanf("%d", &n);
    getchar();
    char string[20];
    StringBuilder* ptr = create_string();
    for (int i = 0; i<n; i++){   
        printf("%d string: ", i+1);
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        append_text(ptr, string);
    }
    printf("Total String: %s\n",get_string(ptr));
    free_stringbuilder(ptr);
    return 0;
}