<h1>Bank Account Management System<h1>
Overview
This Bank Account Management System is a C program designed to manage basic banking operations such as creating accounts, depositing funds, withdrawing funds, checking account balances, and viewing transaction statements. The system supports up to 100 accounts and tracks up to 100 transactions per account.

Features
Account Creation: Users can create a new bank account by entering the account holder's name. Each account is assigned a unique 8-digit account number starting with "232".
Deposit Funds: Users can deposit money into their accounts. The system ensures that only positive amounts are accepted and updates the account balance accordingly.
Withdraw Funds: Users can withdraw money from their accounts if they have sufficient funds. The system checks for sufficient balance and updates the account balance after withdrawal.
Check Balance: Users can inquire about their current account balance by entering their account number.
Transaction Statement: Users can view the history of all transactions associated with their account, including deposits and withdrawals.
Technical Details
Programming Language: C
Maximum Accounts: 100
Maximum Transactions per Account: 100
Random Number Generation: Utilized for generating unique account numbers.
How to Use
Run the Program: Compile and run the C program in a compatible environment.
Main Menu: The main menu offers options to create an account, deposit funds, withdraw funds, check balance, and view transaction statements.
Input Handling: The program uses standard input functions (scanf and fgets) to handle user input and ensures proper validation.
Code Structure
Main Function: The entry point of the program, contains a loop to display the menu and handle user choices.
Function Definitions:
createAccount(): Handles new account creation.
deposit(): Manages fund deposits.
withdraw(): Manages fund withdrawals.
checkBalance(): Displays the account balance.
checkStatement(): Displays the transaction history.
displayMenu(): Displays the main menu.
generateAccountNumber(): Generates a unique account number.
