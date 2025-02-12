// ATMApp.cpp - Implementation of ATMApp class
#include <iostream>
using namespace std;
#include "header/ATMApp.h"

// Runs the ATM application
void ATMApp::run()
{
    // create atminstace
    // add user to atm
    while (true)
    {
        // Avoids skipping initialization

        // Display a welcome message to the user

        // Prompt the user to enter their account number

        // Store the entered account number

        // Prompt the user to enter their PIN for authentication

        // Store the entered PIN

        // Authenticate the user by checking the account number and PIN
        ATMUser *user = atm.authenticateUser(accountNo, pin);

        // If authentication fails, display an error message and restart the loop

        // Start an infinite loop to display the ATM menu and process user actions
        while (true)
        {

            // Process the user's selection using a switch statement
            switch (choice)
            {
            case 1:
                // Display the user's account balance

                break;
            case 2:
                // Prompt the user to enter an amount to withdraw

                // Call the withdrawCash function to process the transaction

                break;
            case 3:
                // Display the user's account details

                break;
            case 4:
                // Prompt the user to enter their old and new mobile numbers

                // Call the updateMobileNo function to update the number

                break;
            case 5:
                // Exit the ATM application
                return;
            default:
                // Handle invalid menu choices
            }
        }
    }
}
