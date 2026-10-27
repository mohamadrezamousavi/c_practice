# include <stdio.h>
# include <string.h>

int main ()
{
    char word1[100], word2[100];
    char combined [200];
    printf("Enter word1: ");
    scanf ("%99s", word1);
    printf("Enter word2: ");
    scanf ("%99s", word2); 
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    printf("len1: %d\n", len1);   
    printf("len2: %d\n", len2);
    int cmp = strcmp(word1, word2);
    printf("comapre: %d", cmp);   
    return 0;
}