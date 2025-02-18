// ATMApp.cpp - Implementation of ATMApp class
#include <iostream>
using namespace std;
#include "header/ATMApp.h"

// Runs the ATM application
void ATMApp::run()
{
    ATM atm;
    atm.addUser(ATMUser(1234567, "Tim", 1111, 45000.90, "9087654321"));

    while (true)
    {
        long int accountNo;
        int pin;
        int choice;
        double amount;       // Declare all variables before the switch
        string oldNo, newNo; // Avoids skipping initialization

        cout << "\n**** Welcome to ATM ****\n";
        cout << "Enter Account Number: ";
        cin >> accountNo;
        cout << "Enter PIN: ";
        cin >> pin;

        ATMUser *user = atm.authenticateUser(accountNo, pin);
        if (!user)
        {
            cout << "Invalid credentials. Try again.\n";
            continue;
        }

        while (true)
        {
            cout << "\n1. Check Balance\n2. Cash Withdrawal\n3. Show User Details\n4. Update Mobile No.\n5. Deposit Money\n6. Exit\nSelect option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                // Display the user's account balance
                cout << "Balance: " << user->getBalance() << "\n";
                break;
            case 2:
                // Prompt the user to enter an amount to withdraw
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                user->withdrawCash(amount);
                break;
            case 3:
                // Display the user's account details
                cout << "Account No: " << user->getAccountNo() << "\n";
                cout << "Name: " << user->getName() << "\n";
                cout << "Balance: " << user->getBalance() << "\n";
                cout << "Mobile No: " << user->getMobileNo() << "\n";
                break;
            case 4:
                // Prompt the user to enter their old and new mobile numbers
                cout << "Enter old mobile no: ";
                cin >> oldNo;
                cout << "Enter new mobile no: ";
                cin >> newNo;
                user->updateMobileNo(oldNo, newNo);
                break;
            case 5:
                // Prompt the user to enter an amount to deposit
                cout << "Enter deposit amount: ";
                cin >> amount;
                user->depositCash(amount);
                break;
            case 6:
                // Exit the ATM application
                return;
            default:
                // Handle invalid menu choices
                cout << "Invalid option. Try again.\n";
            }
        }
    }
}
