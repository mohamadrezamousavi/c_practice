# include <stdio.h>
# include <string.h>

int main ()
{
    char admin_username [100] = "reza";
    char admin_password [100] = "mm123";

    char client_username [100];
    char client_password [100];
    printf("Enter username: ");
    scanf("%s",client_username);
    printf("Enter password: ");
    scanf("%s",client_password);    

    int username_cmp = strcmp(admin_username, client_username);
    int password_cmp = strcmp(admin_password, client_password);
    int n = 0;


    if (username_cmp == 0 && password_cmp == 0)
    {
        printf("Login successful\n");
        n++;
    }
    else if (username_cmp != 0 && password_cmp != 0)
    {
        printf("Invalid credentials\n");
    }

    else if (username_cmp == 0 && password_cmp != 0)
    {
        printf("Invalid password\n");
    }

    else if (username_cmp != 0 && password_cmp == 0)
    {
        printf("Invalid username\n");
    }

    printf("Total successful logins: %d\n", n);

    return 0;
}