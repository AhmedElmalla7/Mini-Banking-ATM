#include "sharedFunctions.h"

void deposit(Account *account)
{
    s32 deposit_amount = 0;

    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;36m              DEPOSIT                  \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    printf("\nEnter deposit amount: ");
    scanf("%d", &deposit_amount);

    if (deposit_amount > 0)
    {
        account->balance += (u32)deposit_amount;
        account->depositCount++;

        printf("\n\033[1;32mDeposit successful.\033[0m\n");
        printf("New balance: EGP %u\n", account->balance);
    }
    else
    {
        printf("\n\033[1;31mInvalid amount.\033[0m\n");
        printf("Enter a value greater than zero.\n");
        printf("Current balance: EGP %u\n", account->balance);
    }
}


void withdraw(Account *account)
{
    s32 withdrawal_amount = 0;

    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;36m             WITHDRAW                  \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    printf("\nEnter withdrawal amount: ");
    scanf("%d", &withdrawal_amount);

    if (withdrawal_amount > 0)
    {
        if ((u32)withdrawal_amount <= account->balance)
        {
            account->balance -= (u32)withdrawal_amount;
            account->withdrawalCount++;

            printf("\n\033[1;32mWithdrawal successful.\033[0m\n");
            printf("New balance: EGP %u\n", account->balance);
        }
        else
        {
            printf("\n\033[1;31mWithdrawal rejected.\033[0m\n");
            printf("Insufficient balance.\n");
            printf("Current balance: EGP %u\n", account->balance);
        }
    }
    else
    {
        printf("\n\033[1;31mInvalid amount.\033[0m\n");
        printf("Enter a value greater than zero.\n");
        printf("Current balance: EGP %u\n", account->balance);
    }
}


void showBalance(const Account *account)
{
    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;36m          ATM BALANCE INQUIRY           \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    printf("\nAccount Name    : %s\n", account->name);
    printf("Current Balance : \033[1;32mEGP %u\033[0m\n", account->balance);

    printf("\n\033[1;34m========================================\033[0m\n");
}


void showSummary(const Account *account)
{
    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;36m            SESSION SUMMARY             \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    printf("\nCustomer            : %s\n", account->name);
    printf("Deposits completed  : %u\n", account->depositCount);
    printf("Withdrawals         : %u\n", account->withdrawalCount);
    printf("Final balance       : \033[1;32mEGP %u\033[0m\n",
           account->balance);

    printf("\n\033[1;34m========================================\033[0m\n");
}