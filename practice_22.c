// This practice is just a game : rock paper Scissor
# include <stdio.h>
# include <string.h>
# include <stdlib.h> //for rand function
# include <stdint.h>
# include <time.h>

typedef enum 
{
    Rock,
    Paper,
    Scissor
} Choices;

void userChoice(char *aptr, uint8_t *num);
Choices computerChoice(void);
void compare(uint8_t *aptr, uint8_t *bptr);

int main ()
{
    srand(time(NULL));
    printf("This is rock paper Scissors game ⛰️ 📄 ✂️\n\n");
    char str[10];
    uint8_t num;
    uint8_t random;
    while (str[0] != 'q' && str[0] != '0')
    {
        printf("\nChoose: ⛰️ Rock, 📄 Paper, or ✂️ Scissors: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        if (strcmp(str, "q") == 0 || strcmp(str, "0") == 0)
        {
            break;
        }
        userChoice(str, &num);

        random = computerChoice();

        compare (&random, &num);

    } 
    return 0;
}

void userChoice(char *aptr, uint8_t *num)
{
        if (strcmp(aptr, "r") == 0 || strcmp(aptr, "rock") == 0
         || strcmp(aptr, "Rock") == 0 || strcmp(aptr, "R") == 0)
        {
            printf("Your Chice is ROCK ⛰️\n");
            *num = 0;
        }
        else if (strcmp(aptr, "p") == 0 || strcmp(aptr, "paper") == 0
         || strcmp(aptr, "Paper") == 0 || strcmp(aptr, "P") == 0)
        {
            printf("Your Chice is PAPER 📄\n");
            *num = 1;
        }
        else if (strcmp(aptr, "s") == 0 || strcmp(aptr, "scissors") == 0
         || strcmp(aptr, "Scissors") == 0 || strcmp(aptr, "S") == 0)
        {
            printf("Your Chice is SCISSORS ✂️\n");
            *num = 2;
        }        
}

Choices computerChoice(void)
{
    return rand() % 3;
}

void compare(uint8_t *aptr, uint8_t *bptr)
{
    if (*aptr == 0)
    {
        printf("computer choice is ROCK ⛰️\n");
        if (*bptr == 0)
        {
            printf("Both choices are ROCK, do it again\n");
        }
        else if( *bptr == 1)
        {
            printf("You win 🎉\n");
        }
        else if ( *bptr == 2)
        {
            printf("You lose 😢\n");
        }
        
    }
    if (*aptr == 1)
    {
        printf("computer choice is PAPER 📄\n");
        if (*bptr == 0)
        {
            printf("You lose 😢\n");
        }
        else if( *bptr == 1)
        {
            printf("Both choices are PAPER, do it again\n");
        }
        else if ( *bptr == 2)
        {
            printf("You Win 🎉\n");
        }
        
    }
    if (*aptr == 2)
    {
        printf("computer choice is SCISSORS ✂️\n");
        if (*bptr == 0)
        {
            printf("You Win 🎉\n");
        }
        else if( *bptr == 1)
        {
            printf("You lose 😢\n");
        }
        else if ( *bptr == 2)
        {
            printf("Both choices are Scissor, do it again\n");
        }
        
    }
}

