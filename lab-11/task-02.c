#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_ACCOUNTS 100

 

struct Transaction {
    char date[20];
    char type[15];      
    float amount;
};

struct Account {
    int accountNumber;
    char name[50];
    char type[20];      
    float balance;

    char creationDate[20];
    char lastTransactionDate[20];

    struct Transaction history[MAX_TRANSACTIONS];
    int transactionCount;
};


struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;



float getMinimum(char *type) {
    if (strcmp(type, "Savings") == 0) return 1000;
    if (strcmp(type, "Current") == 0) return 5000;
    if (strcmp(type, "Fixed Deposit") == 0) return 10000;
    return 0;
}


float getInterestRate(char *type) {
    if (strcmp(type, "Savings") == 0) return 4;
    if (strcmp(type, "Fixed Deposit") == 0) return 7;
    if (strcmp(type, "Current") == 0) return 0;
    return 0;
}



void addTransaction(struct Account *acc, char *type, float amount, char *date) {
    int i;
    i = acc->transactionCount;

    strcpy(acc->history[i].date, date);
    strcpy(acc->history[i].type, type);
    acc->history[i].amount = amount;

    acc->transactionCount++;
    strcpy(acc->lastTransactionDate, date);
}



void createAccount() {
    struct Account acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accountNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);

    printf("Enter Account Type (Savings / Current / Fixed Deposit): ");
    scanf(" %[^\n]", acc.type);


    acc.balance = getMinimum(acc.type);

    printf("Enter Account Creation Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", acc.creationDate);

    strcpy(acc.lastTransactionDate, acc.creationDate);

    acc.transactionCount = 0;

    accounts[accountCount] = acc;
    accountCount++;

    printf("\nAccount Created Successfully! Minimum Balance Added.\n");
}



int findAccount(int accNo) {
    int i;
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo)
            return i;
    }
    return -1;
}



void depositMoney() {
    int accNo, index;
    float amount;
    char date[20];

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", date);

    accounts[index].balance += amount;
    addTransaction(&accounts[index], "Deposit", amount, date);

    printf("Amount Deposited Successfully.\n");
}



void withdrawMoney() {
    int accNo, index;
    float amount;
    float minBal;
    char date[20];

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    minBal = getMinimum(accounts[index].type);

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (accounts[index].balance - amount < minBal) {
        printf("ERROR: Cannot go below minimum balance!\n");
        return;
    }

    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", date);

    accounts[index].balance -= amount;
    addTransaction(&accounts[index], "Withdrawal", amount, date);

    printf("Amount Withdrawn Successfully.\n");
}



void displayAccount() {
    int accNo, index, i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("\n----- ACCOUNT DETAILS -----\n");
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Name: %s\n", accounts[index].name);
    printf("Type: %s\n", accounts[index].type);
    printf("Balance: %.2f\n", accounts[index].balance);
    printf("Interest Rate: %.2f%%\n", getInterestRate(accounts[index].type));
    printf("Created On: %s\n", accounts[index].creationDate);
    printf("Last Transaction: %s\n", accounts[index].lastTransactionDate);

    printf("\n--- TRANSACTION HISTORY ---\n");
    for (i = 0; i < accounts[index].transactionCount; i++) {
        printf("%s - %s: %.2f\n",
               accounts[index].history[i].date,
               accounts[index].history[i].type,
               accounts[index].history[i].amount);
    }
}



int main() {
    int choice;

    while (1) {
        printf("\n===============================\n");
        printf(" BANK ACCOUNT MANAGEMENT SYSTEM\n");
        printf("===============================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) createAccount();
        else if (choice == 2) depositMoney();
        else if (choice == 3) withdrawMoney();
        else if (choice == 4) displayAccount();
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
