# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main ()
{
    char sentence[200];
    printf("Enter a Sentence: \n");
    fgets(sentence, sizeof(sentence), stdin);
    printf("your text: %s", sentence);
    int len = strlen(sentence);
    printf("len: %d\n", len);
    char upper[200];
    for (int i = 0; i < len; i++)
    {
        upper[i] = toupper(sentence[i]);
    }
    
    printf("your text: %s", upper);
    return 0;
}