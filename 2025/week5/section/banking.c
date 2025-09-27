// simple bank application in c
#include <stdio.h>

void checkBal(float balance);
float deposit();
float withdraw(float balance);

int main()
{
    int choice = 0;
    float balance = 0.0f;

    printf("*** Welcome! To The ABC Bank ***");

    do{
        printf("\nSelect an Option: \n");
        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdway Money");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
                checkBal(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("\nThankyou for using the bank!");
                break;
            default:
                printf("\nInvalid Choice, Pls select 1-4\n");
        }

    }while(choice != 4);
    return 0;
}

void checkBal(float balance)
{
    printf("Your Current balance is : $%.2f\n", balance);
}

float deposit()
{
    float amount = 0.0f;

    printf("\nEnter Amount to deposit: ");
    scanf("%f", &amount);

    if (amount < 0)
    {
        printf("Invalid amount!");
        return 0.0f;
    }
    else
    {
        printf("Succenfully deposited $%.2f\n", amount);
        return amount;
    }
}

float withdraw(float balance)
{
    float amount = 0.0f;
    printf("\nEnter Amount to Withdraw: $");
    scanf("%f", &amount);

    if (amount > balance || amount < 0)
    {
        printf("Invalid amount! or Insufficient Funds!");
        return balance;
    }
    else
    {
        printf("Successfully Withdrew $%.2f\n", amount);
        return amount;
    }
}
