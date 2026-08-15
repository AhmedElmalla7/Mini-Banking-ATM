#include "sharedFunctions.h"

void readPinAsStars(u8 *pinBuf, u32 maxLen)
{
    u32 i = 0;
    u8 ch;

    while (1)
    {
        ch = getchar(); // important fix it before final edition

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
    printf("\n");
    printf("====================================\n");
    if (currentLang == LANG_EN)
    {
        printf("||              LOGIN             ||\n");
    }
    else
    {
        printf("||          تسجيل الدخول          ||\n");
    printf("====================================\n");
    while (numberOfAttempts < 3)
    {
        u8 enteredPin[5];
        u8 enteredAccountNumber[12];
    if (currentLang == LANG_EN)
        {
            printf("Enter your account number : ");
        }
        else
        {
            printf("أدخل رقم الحساب : ");
        }
        scanf("%s", enteredAccountNumber);
        getchar(); // new

        if (currentLang == LANG_EN)
        {
            printf("Enter your PIN : ");
        }
        else
        {
            printf("أدخل الرقم السري : ");
        }
        readPinAsStars((u8 *)enteredPin, 5);

        if (strlen((u8 *)enteredPin) != 4 || strlen((u8 *)enteredAccountNumber) != 4)
        {
            if (currentLang == LANG_EN)
            {
                printf("Invalid input. Please ensure the account number is 4 digits and the PIN is 4 digits.\n");
                numberOfAttempts++;
                printf("You have %d attempts left.\n", 3 - numberOfAttempts);
            }
            else
            {
                printf("إدخال غير صحيح. تأكد أن رقم الحساب والرقم السري يتكونان من 4 أرقام.\n");
                numberOfAttempts++;
                printf("لديك %d محاولات متبقية.\n", 3 - numberOfAttempts);
            }
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
           if (currentLang == LANG_EN)
            {
                printf("You have exceeded the maximum number of login attempts. Exiting the program.\n");
            }
            else
            {
                printf("لقد تجاوزت الحد الأقصى لمحاولات تسجيل الدخول. يتم الخروج.\n");
            }
            return NULL; // new
            // exit(1);
        }

        if (currentLang == LANG_EN)
        {
            printf("Invalid account number or PIN. You have %d attempts left.\n", 3 - numberOfAttempts);
        }
        else
        {
            printf("رقم الحساب أو الرقم السري غير صحيح. لديك %d محاولات متبقية.\n", 3 - numberOfAttempts);
        }
    }
    return NULL; // new
}