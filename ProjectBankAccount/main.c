#include <stdio.h>
#include "account.h"

int main(){
    int id;
    printf("Enter Cleint ID: ");
    scanf("%d",&id);
    Account *a = create_account(id);
    printf("Account is created with %d id\n", id);
    double deposit_amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &deposit_amount);
    int deposit_valid = deposit(a, deposit_amount);

    if (deposit_valid == 0) printf("Invalid deposit\n");
    else{
        printf("deposit successful\n");
    }
    printf("current balance is: %f\n", get_balance(a));
    double withdraw_amount;
   printf("Enter amount to withdraw: ");
    scanf("%lf", &withdraw_amount);    
    int withdraw_valid = withdraw(a, withdraw_amount);

    if (withdraw_valid == 0) printf("Invalid Withdraw\n");
    else printf("Withdraw Successful\n");
    printf("current balance is: %f\n", get_balance(a));
    destroy_account(a);
    printf("Account destroyed\n");
    return 0;
}