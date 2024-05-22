#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum number of accounts
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
    char transactions[MAX_TRANSACTIONS][100];
    int numTransactions;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void checkStatement();
void displayMenu();
int generateAccountNumber();

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                checkStatement();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n*** Bank Account Management System ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Check Statement\n");
    printf("6. Exit\n");
}

int generateAccountNumber() {
    // Generate a random 5-digit number
    int randomPart = rand() % 100000; // 0 to 99999
    // Combine the prefix "232" with the random part
    return 23200000 + randomPart;
}

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = generateAccountNumber();

    printf("Enter account holder name: ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    // Remove the trailing newline character if it's there
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0';

    newAccount.balance = 0.0f;
    newAccount.numTransactions = 0;

    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount. Please enter a positive value.\n");
                return;
            }

            accounts[i].balance += amount;
            snprintf(accounts[i].transactions[accounts[i].numTransactions], 100, "Deposited: %.2f Taka", amount);
            accounts[i].numTransactions++;
            printf("Amount deposited successfully! New balance: %.2f Taka\n", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Invalid account number.\n");
    }
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount. Please enter a positive value.\n");
                return;
            }

            if (accounts[i].balance < amount) {
                printf("Insufficient balance.\n");
                return;
            }

            accounts[i].balance -= amount;
            snprintf(accounts[i].transactions[accounts[i].numTransactions], 100, "Withdrew: %.2f Taka", amount);
            accounts[i].numTransactions++;
            printf("Amount withdrawn successfully! New balance: %.2f\n Taka", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Invalid account number.\n");
    }
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Account Balance for Account Number %d: %.2f Taka\n", accountNumber, accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Invalid account number.\n");
    }
}

void checkStatement() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Transaction history for Account Number %d:\n", accountNumber);
            for (int j = 0; j < accounts[i].numTransactions; j++) {
                printf("%d. %s\n", j + 1, accounts[i].transactions[j]);
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid account number.\n");
    }
}
