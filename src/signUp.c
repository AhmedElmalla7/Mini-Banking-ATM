#include "sharedFunctions.h"

u32 activeCount = 3;

void signUp(Account *accountPointers[], s32 *userCount, Account accounts[])
{
    // check if its full.(not done yet)
    if (*userCount >= ACCOUNT_COUNT)
    {
        clearScreen();

        printf("\n\033[1;34m====================================================\033[0m\n");
        printf("\033[1;31m Max number of users reached please try again later \033[0m\n");
        printf("\033[1;34m====================================================\033[0m\n\n");

        printf("\033[1;33mPress Enter to return to Main Menu...\033[0m");
        getchar();

        return;
    }

    // --- 1. HEADER ---
    clearScreen();

    printf("\n\033[1;34m==========================================\033[0m\n");
    printf("\033[1;36m        ATM SYSTEM - NEW ACCOUNT         \033[0m\n");
    printf("\033[1;34m==========================================\033[0m\n\n");

    // --- 2. INPUT PROMPTS ---
    // Maps to: account.name
    printf("\033[1;33mPlease enter your full name : \033[0m");

    if (fgets(accounts[*userCount].name,
              sizeof(accounts[*userCount].name),
              stdin) != NULL)
    {
        s32 fullNameStored = 0;

        while (!fullNameStored)
        {
            size_t len = strlen((char *)accounts[*userCount].name);

            if (!(len > 0 &&
                  (char)accounts[*userCount].name[len - 1] == '\n'))
            {
                // the full name was not stored(no enough space.)
                s32 characterDelete;

                while ((characterDelete = getchar()) != '\n' &&
                       characterDelete != EOF)
                {
                    // empty out the buffer
                }

                // try again with shorter name
                printf("\n\033[1;31mName exceeded the limit pleas enter your full name again: \033[0m");

                fgets((char *)accounts[*userCount].name,
                      sizeof(accounts[*userCount].name),
                      stdin);

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
    {
        // Loop stops BEFORE *userCount
        if (ignoreCaseComp(accounts[*userCount].name, accounts[i].name))
        {
            printf("\n\033[1;31mUser already exists.\033[0m\n");

            printf("\n\033[1;33mPress Enter to return to Main Menu...\033[0m");
            getchar();

            return;
        }
    }

    // getting information from user.
    printf("\n\033[1;36mSelect Account Type:\033[0m\n");
    printf("  \033[1;36m[1]\033[0m Savings\n");
    printf("  \033[1;36m[2]\033[0m Current\n");

    printf("\033[1;33mEnter choice (1 or 2): \033[0m");

    u32 accType;
    scanf("%u", &accType);

    while (accType > 2 || accType < 1)
    {
        printf("\033[1;31mEnter choice (1 or 2): make sure you selected one of them \033[0m");
        scanf("%u", &accType);
    }

    accounts[*userCount].type = accType - 1;

    // user balance and settinng the rest of parameeters
    u32 depo;

    // scanf returns 1 if success.
    u32 depoCheck = 0;

    while (depoCheck != 1)
    {
        printf("\n\033[1;33mEnter initial deposit amount : $\033[0m");

        depoCheck = scanf("%u", &depo);

        if (depoCheck != 1)
        {
            printf("\033[1;31mInvalid input.\033[0m\n");
            depoCheck = 0;
        }
        else if (depo <= 0)
        {
            printf("\033[1;31mDeposit amount cannot be zero or negative. Please enter a valid amount.\033[0m\n");
            depoCheck = 0;
        }
        else
        {
            accounts[*userCount].balance = depo;
            break;
        }

        u32 c;

        while ((c = getchar()) != '\n' && c != EOF)
        {
            // This loop reads and discards the invalid characters
        }
    }

    accounts[*userCount].balance = depo;
    accounts[*userCount].depositCount = 1;
    accounts[*userCount].withdrawalCount = 0;

    // getting the pin and number
    getchar();

    printf("\n\033[1;33mCreate a 4-digit PIN: \033[0m");

    u8 enteredPin[5];

    // not working on mac
    readPinAsStars((u8 *)enteredPin, 5);

    // check if pin is 4 digits only
    while (strlen((u8 *)enteredPin) != 4)
    {
        printf("\n\033[1;31mMAke sure it is a 4-digit PIN: \033[0m");
        readPinAsStars((u8 *)enteredPin, 5);
    }

    // incrementing last user input
    u32 newUserAccNum =
        atoi((char *)accounts[(*userCount) - 1].accountNumber) + 1;

    strcpy(accounts[*userCount].pin, enteredPin);

    snprintf((char *)accounts[*userCount].accountNumber,
             sizeof(accounts[*userCount].accountNumber),
             "%u",
             newUserAccNum);

    // Confirmation message
    clearScreen();

    printf("\n\033[1;34m==========================================\033[0m\n");
    printf("\033[1;32m      ACCOUNT CREATED SUCCESSFULLY!      \033[0m\n");
    printf("\033[1;34m==========================================\033[0m\n");

    printf("Account Name   : %s\n",
           accounts[*userCount].name);

    if (accounts[*userCount].type == SAVINGS)
    {
        printf("Account Type   : Savings\n");
    }
    else
    {
        printf("Account Type   : Current\n");
    }

    printf("Account Number : \033[1;33m%s\033[0m\n",
           accounts[*userCount].accountNumber);

    printf("Initial Balance: \033[1;32m$%u\033[0m\n",
           accounts[*userCount].balance);

    printf("\033[1;34m==========================================\033[0m\n");

    printf("\033[1;33mPlease memorize your PIN. Do not share it.\033[0m\n");

    printf("\033[1;33mPress any key to return to Main Menu...\033[0m\n");

    accountPointers[*userCount] = &accounts[*userCount];

    (*userCount)++;

    _getch();
}


// this should hide the pin
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
            return 0;
        }

        i++;
    }

    // Returns 1 if both strings reached the null-terminator at the same time
    return s1[i] == s2[i];
}