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
    u32 numberOfAttempts = 0;

    while (numberOfAttempts < 3)
    {
        clearScreen();

        printf("\n\033[1;34m========================================\033[0m\n");
        printf("\033[1;36m                 LOGIN                  \033[0m\n");
        printf("\033[1;34m========================================\033[0m\n");

        printf("\n\033[1;33mLogin attempts remaining: %u\033[0m\n\n",
               3 - numberOfAttempts);

        u8 enteredPin[5];
        u8 enteredAccountNumber[12];

        printf("\nEnter your account number : ");
        scanf("%s", enteredAccountNumber);
        getchar();

        printf("Enter your PIN : ");
        readPinAsStars(enteredPin, 5);

        if (strlen((char *)enteredPin) != 4 ||
            strlen((char *)enteredAccountNumber) != 4)
        {
            numberOfAttempts++;

            printf("\n\033[1;31mInvalid input.\033[0m\n");
            printf("Account number and PIN must be 4 digits.\n");

            if (numberOfAttempts < 3)
            {
                printf("\nYou have %u login attempts remaining.\n",
                       3 - numberOfAttempts);

                printf("\nPress Enter to continue...");
                getchar();
            }

            continue;
        }

        for (u32 i = 0; i < count; i++)
        {
            if (strcmp((char *)enteredAccountNumber,
                       (char *)list[i]->accountNumber) == 0 &&
                strcmp((char *)enteredPin,
                       (char *)list[i]->pin) == 0)
            {
                return list[i];
            }
        }

        numberOfAttempts++;

        if (numberOfAttempts < 3)
        {
            printf("\n\033[1;31mInvalid account number or PIN.\033[0m\n");
            printf("You have %u login attempts remaining.\n",
                   3 - numberOfAttempts);

            printf("\nPress Enter to try again...");
            getchar();
        }
    }

    // Maximum attempts reached
    clearScreen();

    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;31m              ACCESS DENIED             \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    printf("\nToo many incorrect login attempts.\n");
    printf("For your security, access has been denied.\n");
    printf("Your login session has been terminated.\n");

    printf("\n\033[1;36mPress Enter to continue...\033[0m");

    getchar();

    return NULL;
}