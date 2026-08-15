#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "STD_TYPES.h"
#define ACCOUNT_COUNT 10

typedef enum
{
    SAVINGS,
    CURRENT
} AccountType;

typedef enum
{
    SIGNIN = 1,
    SIGNUP,
    EXIT
} MainOperation;

typedef struct
{
    u8 pin[5];
    u8 accountNumber[12];
    u8 name[40];
    AccountType type;
    u32 balance;
    u32 depositCount;
    u32 withdrawalCount;
} Account;

// Function prototypes

// Auth function
void readPinAsStars(u8 *pinBuf, u32 maxLen);
Account *login(Account *list[], u32 count);

// transaction functions
void showBalance(const Account *account);
void deposit(Account *account);
void withdraw(Account *account);

// summary function
void showSummary(const Account *account);

// atmMenu function
void atmMenu(Account *account);
// signup
void signUp(Account *accountPointers[], s32 *userCount, Account accounts[]);
u32 ignoreCaseComp(const u8 *s1, const u8 *s2);

#endif