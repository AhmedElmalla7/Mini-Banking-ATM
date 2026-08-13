#include <stdio.h>
#include "sharedFunctions.h"

int main(void)
{
    // intialize accounts
    Account accounts[ACCOUNT_COUNT] = {
        {"1234" , "1001" , "Sara Ahmed",  SAVINGS , 5000.0f, 0, 0}, 
        {"5678" , "1002" , "Omar Ali"  ,  CURRENT , 3500.0f, 0, 0}, 
        {"4321" , "1003" , "Mona Adel" ,  SAVINGS , 7200.0f, 0, 0}
    }; 

    // a pointer array that refers to accounts
    Account *accountPointers[ACCOUNT_COUNT]; 

    for (int i = 0; i < ACCOUNT_COUNT; i++) {   
        accountPointers[i] = &accounts[i]; 
    }   

    

    return 0;
}