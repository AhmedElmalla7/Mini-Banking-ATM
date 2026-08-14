#include <stdio.h>
#include "sharedFunctions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

s32 activeCount = 3;
void signUp(Account *accountPointers[], s32 *userCount, Account accounts[]);
void readPinAsStars(u8 *pinBuf, u32 maxLen);
u32 ignoreCaseComp(const u8 *s1, const u8 *s2);
int main(void)
{
    //

    // intialize accounts
    Account accounts[ACCOUNT_COUNT] = {
        {"1234", "1001", "Sara Ahmed", SAVINGS, 5000.0f, 0, 0},
        {"5678", "1002", "Omar Ali", CURRENT, 3500.0f, 0, 0},
        {"4321", "1003", "Mona Adel", SAVINGS, 7200.0f, 0, 0}};

    // a pointer array that refers to accounts
    Account *accountPointers[ACCOUNT_COUNT];

    for (int i = 0; i < ACCOUNT_COUNT; i++)
    {
        accountPointers[i] = &accounts[i];
    }
    signUp(accountPointers, &activeCount, accounts);
    // just to depug
    printf("\n\n==========================================\n");
    printf("        SYSTEM DATABASE CHECK             \n");
    printf("==========================================\n");

    for (int i = 0; i < activeCount; i++)
    {
        printf("\n--- ACCOUNT %d ---\n", i + 1);

        // 1. Printing from the heavy struct array (using the dot '.')
        printf("[From Struct Array]\n");
        printf("Name   : %s\n", accounts[i].name);
        printf("Acc #  : %s\n", accounts[i].accountNumber);
        printf("PIN    : %s\n", accounts[i].pin);
        printf("Type   : %d\n", accounts[i].type);
        printf("Balance: $%u\n", accounts[i].balance);

        // 2. Printing from the pointer array (using the arrow '->')
        printf("\n[From Pointer Array]\n");
        printf("Name   : %s\n", accountPointers[i]->name);
        printf("Balance: $%u\n", accountPointers[i]->balance);
    }
    printf("\n==========================================\n");

    return 0;
}

void signUp(Account *accountPointers[], s32 *userCount, Account accounts[])
{
    // check if its full.(not done yet)
    if (*userCount >= ACCOUNT_COUNT)
    {
        printf("\n====================================================\n");
        printf(" Max number of users reached please try again later\n");
        printf("======================================================\n\n");
        return;
    }

    // --- 1. HEADER ---
    printf("\n==========================================\n");
    printf("        ATM SYSTEM - NEW ACCOUNT          \n");
    printf("==========================================\n\n");

    // --- 2. INPUT PROMPTS ---
    // Maps to: account.name
    printf("Please enter your full name: ");

    if (fgets(accounts[*userCount].name, sizeof(accounts[*userCount].name), stdin) != NULL)
    {

        s32 fullNameStored = 0;
        while (!fullNameStored)
        {
            size_t len = strlen((char *)accounts[*userCount].name);
            if (!(len > 0 && (char *)accounts[*userCount].name[len - 1] == '\n'))
            {
                // the full name was not stored(no enough space.)
                s32 characterDelete;
                while ((characterDelete = getchar()) != '\n' && characterDelete != EOF)
                {
                    // empty out the buffer
                }
                // try again with shorter name
                printf("\n Name exceeded the limit pleas enter your full name again: ");
                fgets((char *)accounts[*userCount].name, sizeof(accounts[*userCount].name), stdin);
                continue;
            }
            else
            {
                accounts[*userCount].name[len - 1] = '\0';
                fullNameStored = 1;
            }
        }
    }
    else
    {
        // error if no name provided
    }

    // if user already there.
    for (int i = 0; i < *userCount; i++)
    { // Loop stops BEFORE *userCount
        if (ignoreCaseComp(accounts[*userCount].name, accounts[i].name))
        {
            printf("Get the hell out.\n");
            return;
        }
    }

    // getting information from user.
    printf("\nSelect Account Type:\n");
    printf("  [1] Savings\n");
    printf("  [2] Current\n");
    printf("Enter choice (1 or 2): ");
    u32 accType;
    scanf("%u", &accType);
    while (accType > 2 || accType < 1)
    {
        printf("Enter choice (1 or 2): make sure you selected one of them ");
        scanf("%u", &accType);
    }

    accounts[*userCount].type = accType - 1;

    // user balance and settinng the rest of parameeters
    printf("\nEnter initial deposit amount: $");
    u32 depo;
    // scanf returns 1 if success.
    u32 depoCheck;
    while (depoCheck != 1)
    {
        printf("\nEnter initial deposit amount: $");
        depoCheck = scanf("%u", &depo);
        if (depoCheck == 1)
        {
            break;
        }
        u32 c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            // This loop reads and discards the invalid characters (like "abc")
            // until it hits the end of the line.
        }
    }

    accounts[*userCount].balance = depo;
    accounts[*userCount].depositCount = 1;
    accounts[*userCount].withdrawalCount = 0;

    // getting the pin and number
    getchar();
    printf("\nCreate a 4-digit PIN: ");

    u8 enteredPin[5];
    // u8 enteredAccountNumber[12];
    // not working on mac
    readPinAsStars((u8 *)enteredPin, 5);
    // check if pin is 4 digits only
    while (strlen((u8 *)enteredPin) != 4)
    {
        printf("\nMAke sure it is a 4-digit PIN: ");
        readPinAsStars((u8 *)enteredPin, 5);
    }

    //
    // printf("\nEnter your account number : ");
    // scanf("%s", enteredAccountNumber);
    // incrementing last user input
    u32 newUserAccNum = atoi((char *)accounts[(*userCount) - 1].accountNumber) + 1;
    // printf("\nthe number as number is %u\n",newUserAccNum);
    //
    strcpy(accounts[*userCount].pin, enteredPin);
    // strcpy(accounts[*userCount].accountNumber, (u8)newUserAccNum);
    snprintf((char *)accounts[*userCount].accountNumber,
             sizeof(accounts[*userCount].accountNumber),
             "%u", newUserAccNum);

    // Confirmation message
    printf("\n\n==========================================\n");
    printf("      ACCOUNT CREATED SUCCESSFULLY!       \n");
    printf("==========================================\n");
    printf("Account Name   : %s\n", accounts[*userCount].name);
    printf("Account Type   : %d\n", accounts[*userCount].type);
    printf("Account Pin   : %s\n", accounts[*userCount].pin);
    printf("Account Number : %s\n", accounts[*userCount].accountNumber); // The system usually generates this!
    printf("Initial Balance: $%u\n", accounts[*userCount].balance);      // Using %u since your balance is a u32
    printf("==========================================\n");
    printf("Please memorize your PIN. Do not share it.\n");
    printf("Press any key to return to Main Menu...\n");
    accountPointers[*userCount] = &accounts[*userCount];
    (*userCount)++;
}
// this should hide the pin
void readPinAsStars(u8 *pinBuf, u32 maxLen)
{
    u32 i = 0;
    u8 ch;

    while (1)
    {
        ch = getchar();

        if (ch == '\r' || ch == '\n')
        {
            pinBuf[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == '\b' || ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (i < maxLen - 1)
        {
            pinBuf[i] = ch;
            i++;
            printf("*");
        }
    }
}
u32 ignoreCaseComp(const u8 *s1, const u8 *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;

    u32 i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        // No casting needed for tolower since s1[i] is already unsigned char (u8)
        if (tolower(s1[i]) != tolower(s2[i]))
        {
            return 0; // Characters do not match
        }
        i++;
    }
    // Returns 1 if both strings reached the null-terminator at the same time
    return s1[i] == s2[i];
}