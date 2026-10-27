#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countWordOccurrences(char *word1){
    int len = strlen(word1);
    int index = 0;
    for (int i = 0; i < len; i++){
        if (*(word1+i) == ' '){
            index = i;
        }
    }

    return index;

}

int main(){
    char word1[20] = "Hello World!";
    printf("address 0: %p\n - value: %c\n",word1, *word1);
    printf("address 1: %p\n - value: %c\n",(word1+1), *(word1+1));
    int len = strlen(word1);
    printf("len: %d\n", len);
    int index = countWordOccurrences(word1);
    printf("%d\n",index);


    return 0;
}