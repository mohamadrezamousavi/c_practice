#include <stdio.h>
#include <string.h>
#include "wrapper.h"

int main(){
    char type;
    printf("Enter Your Type: ");
    scanf("%c", &type);
    Wrapper w;
    char *string;
    getchar();
    if (type == 'i'){
        int value;
        printf("Enter Value: ");
        scanf("%d", &value);
        w = wrap_int(value);
    }
    else if( type =='s'){
        char string[256];
        printf("Enter your string: ");
        fgets(string, 255, stdin);
        string[strcspn(string,"\n")] = '\0';
        w = wrap_string(string);
    }

    print_wrapper(&w);
    free_wrapper(&w);


}