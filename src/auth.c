#include "sharedFunctions.h"

void readPinAsStars(u8 *pinBuf, u32 maxLen)
{
    u32 i = 0;
    u8 ch;

    while (1)
    {
        ch = _getch(); // important fix it before final edition

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

Account *login(Account *list[], u32 count)
{
    clearScreen();

    u32 numberOfAttempts = 0;
    printf("\n");
    printf("====================================\n");
    printf("||              LOGIN             ||\n");
    printf("====================================\n");
    while (numberOfAttempts < 3)
    {
        u8 enteredPin[5];
        u8 enteredAccountNumber[12];

        printf("Enter your account number : ");

        scanf("%s", enteredAccountNumber);
        getchar(); // new

        printf("Enter your PIN : ");

        readPinAsStars((u8 *)enteredPin, 5);

        if (strlen((u8 *)enteredPin) != 4 || strlen((u8 *)enteredAccountNumber) != 4)
        {

            printf("Invalid input. Please ensure the account number is 4 digits and the PIN is 4 digits.\n");
            numberOfAttempts++;
            printf("You have %d attempts left.\n", 3 - numberOfAttempts);

            continue;
        }

        for (u32 i = 0; i < count; i++)
        {
            if (strcmp((u8 *)enteredAccountNumber, (u8 *)list[i]->accountNumber) == 0 &&
                strcmp((u8 *)enteredPin, (u8 *)list[i]->pin) == 0)
            {
                return list[i];
            }
        }

        numberOfAttempts++;
        if (numberOfAttempts == 3)
        {

            printf("You have exceeded the maximum number of login attempts. Exiting the program.\n");

            return NULL; // new
        }

        printf("Invalid account number or PIN. You have %d attempts left.\n", 3 - numberOfAttempts);
    }
    return NULL; // new
}