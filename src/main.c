#include <stdio.h>
#include "sharedFunctions.h"

Language currentLang = LANG_EN;
extern u32 activeCount;

void selectLanguage(void)
{
    u32 langChoice = 1;
    printf("\n\033[1;35m========================================\033[0m\n");
    printf("\033[1;36m       SELECT LANGUAGE / اختر اللغة      \033[0m\n");
    printf("\033[1;35m========================================\033[0m\n");
    printf("  \033[1;36m[1]\033[0m English\n");
    printf("  \033[1;36m[2]\033[0m العربية\n");
    printf("\033[1;33mChoice: \033[0m");
    scanf("%u", &langChoice);
    getchar();

    if (langChoice == 2)
    {
        currentLang = LANG_AR;
    }
    else
    {
        currentLang = LANG_EN;
    }
}

int main(void)
{
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
    while (1)
    {
        u32 mainOp = 0;
        printf("\n\033[1;34m========================================\033[0m\n");
        printf("\033[1;36m       MINI BANKING & ATM SYSTEM        \033[0m\n");
        printf("\033[1;34m========================================\033[0m\n");
       if (currentLang == LANG_EN)
        {
            printf("\n  \033[1;36m[1]\033[0m \033[1;32mSign In\033[0m\n");
            printf("  \033[1;36m[2]\033[0m \033[1;36mSign Up\033[0m\n");
            printf("  \033[1;31m[3]\033[0m \033[1;31mExit\033[0m\n");
            printf("\n\033[1;33mEnter your choice:\033[0m ");
        }
        else
        {
            printf("\n  \033[1;36m[1]\033[0m \033[1;32mتسجيل الدخول\033[0m\n");
            printf("  \033[1;36m[2]\033[0m \033[1;36mإنشاء حساب جديد\033[0m\n");
            printf("  \033[1;31m[3]\033[0m \033[1;31mخروج\033[0m\n");
            printf("\n\033[1;33mأدخل اختيارك:\033[0m ");
        }
        scanf("%u", &mainOp);
        getchar();
        MainOperation choice = (MainOperation)mainOp;
        switch (choice)
        {
        case SIGNIN:
        {
            Account *userToLog = login(accountPointers, activeCount);
            if (userToLog != NULL)
            {
                atmMenu(userToLog);
            }
            else
            {
                // exit cause of wrong pin
                printf("\n========================================\n");
               if (currentLang == LANG_EN)
                {
                    printf("       Thank you for choosing HsCBN\n");
                }
                else
                {
                    printf("      شكراً لاختيارك بنك HsCBN\n");
                }
                printf("========================================\n");
            }
            break;
        }
        case SIGNUP:
            signUp(accountPointers, &activeCount, accounts);
            break;
        case EXIT:
            return 0;
            break;

        default:
            if (currentLang == LANG_EN)
            {
                printf("\n Invalid choice");
            }
            else
            {
                printf("\n اختيار غير صحيح");
            }
            break;
        }
    }
    return 0;
}