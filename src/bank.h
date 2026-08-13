#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "STD_TYPES.h"
#define ACCOUNT_COUNT 3

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


#endif 