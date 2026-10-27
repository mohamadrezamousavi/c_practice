#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account Account;

Account *create_account(int id);
void destroy_account(Account *self);
int deposit(Account *self, double amount);
int withdraw(Account *self, double amount);
double get_balance(const Account *self);


#endif