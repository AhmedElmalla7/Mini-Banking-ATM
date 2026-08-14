#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#define ACCOUNT_COUNT 10

s32 activeCount = 3;


typedef enum { 
    SAVINGS, 
    CURRENT 
} AccountType; 


typedef struct {  
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
Account *login(Account *list[], int count); 

// transaction functions
void showBalance(const Account *account); 
void deposit(Account *account); 
void withdraw(Account *account);

// summary function
void showSummary(const Account *account);

// atmMenu function
void atmMenu(Account *account);

#endif 