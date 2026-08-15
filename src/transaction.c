#include "sharedFunctions.h"
void deposit(Account *account)
{
    s32 deposit_amount = 0;
    printf("Enter deposit amount:");
    scanf("%d", &deposit_amount);
    if (deposit_amount > 0)
    {
        printf("\033[1;32m Deposit successful. \033[0m\n");
        account->balance += (u32)deposit_amount;
        account->depositCount++;
        printf("New balance: EGP %d \n", account->balance);
    }
    else
    {
        printf("\033[1;31m Invalid amount. Enter a value greater than zero.\n \033[0m\n");
        printf("Current balance: EGP %d \n", account->balance);
    }
}

void withdraw(Account *account)
{
    s32 withdrawal_amount = 0;
    printf("Enter withdrawal amount:");
    scanf("%d", &withdrawal_amount);
    if (withdrawal_amount > 0)
    {
        if ((u32)withdrawal_amount <= account->balance)
        {
            printf("withdrawal successful. \n");
            account->balance -= (u32)withdrawal_amount;
            account->withdrawalCount++;
            printf("New balance: EGP %d \n", account->balance);
        }
        else
        {
            printf("Withdrawal rejected: insufficient balance. \n");
            printf("Current balance: EGP %d \n", account->balance);
        }
    }
    else
    {
        printf("Invalid amount. Enter a value greater than zero.\n");
        printf("Current balance: EGP %d \n", account->balance);
    }
}

void showBalance(const Account *account)
{
    printf("\n========================================\n");
    printf("          ATM BALANCE INQUIRY           \n");
    printf("========================================\n");

    printf(" Account Name: %s\n", account->name);

    printf(" Current Balance: $%.2u\n", account->balance);

    printf("========================================\n");
}
void showSummary(const Account *account)
{
    printf("\nSession summary\n");
    printf("------------- SESSION SUMMARY -------------\n");
    printf("Customer : %s\n", account->name);
    printf("Deposits completed : %d\n", account->depositCount);
    printf("Withdrawals : %d\n", account->withdrawalCount);
    printf("Final balance : EGP %.2u\n", account->balance);
    printf("-------------------------------------------\n");
    printf("Thank you for using our ATM.\n");
}