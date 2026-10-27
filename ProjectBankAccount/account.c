#include <stdlib.h>
#include "account.h"

struct Account
{
    /* data */
    int id;
    double balance;
};

Account *create_account(int id){
    Account *a = malloc(sizeof(Account));
    a->balance = id;
    a->balance = 0;
    return a;
}

void destroy_account(Account *self){
    if (self == NULL) return;
    free(self);
}

int deposit(Account *self, double amount){
    if (amount < 0) return 0;
    else{
        self->balance += amount;
        return 1;
    }
}

int withdraw(Account *self, double amount){
    if (amount > 0 && self->balance > amount){
        self->balance -= amount;
        return 1;
    }
    else return 0;
}

double get_balance(const Account *self){
    return self->balance;
}
