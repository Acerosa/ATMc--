// ATMApp.cpp - Updated to auto-generate account number
#include "header/ATMApp.h"
#include "header/ATMDatabase.h"
#include <limits>
#include <random>

// Function to generate a unique 6-digit account number
long int generateAccountNumber()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<long int> dist(100000, 999999);
    return dist(gen);
}

void ATMApp::run()
{
    ATM atm;
    ATMDatabase db("users.json");
    db.load(atm.getUsers());

    while (true)
    {
        int initialChoice;
        long int accountNo;
        int pin;
        int choice;
        double amount;
        string oldNo, newNo, name, mobileNo;

        cout << "\n**** Welcome to ATM ****\n";
        cout << "1. Create New Account\n2. Access Existing Account\n3. Exit\nSelect option: ";
        cin >> initialChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        if (initialChoice == 1)
        {
            // Create a new account
            cout << "\nEnter new account details:\n";

                    cout << "Name: ";
            getline(cin, name);

            cout << "PIN: ";
            cin >> pin;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Initial Balance: ";
            cin >> amount;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Mobile Number: ";
            getline(cin, mobileNo);

            accountNo = generateAccountNumber(); // ✅ Auto-generate account number
            cout << "Your generated account number is: " << accountNo << "\n";

            // Create and save new user
            ATMUser newUser(accountNo, name, pin, amount, mobileNo);
            atm.addUser(newUser);
            db.addUser(newUser);

            cout << "\nAccount created successfully! Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }
        else if (initialChoice == 2)
        {
            // Access an existing account
            cout << "\nEnter Account Number: ";
            cin >> accountNo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter PIN: ";
            cin >> pin;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ATMUser *user = atm.authenticateUser(accountNo, pin);
            if (!user)
            {
                cout << "Invalid credentials. Try again.\n";
                continue;
            }

            while (true)
            {
                cout << "\n1. Check Balance\n2. Cash Withdrawal\n3. Deposit Money\n4. Update Mobile No.\n5. Delete Account\n6. Logout\nSelect option: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice)
                {
                case 1:
                    cout << "Balance: " << user->getBalance() << "\n";
                    break;
                case 2:
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    user->withdrawCash(amount);
                    db.save(atm.getUsers());
                    break;
                case 3:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    user->depositCash(amount);
                    db.save(atm.getUsers());
                    break;
                case 4:
                    cout << "Enter old mobile no: ";
                    getline(cin, oldNo);
                    cout << "Enter new mobile no: ";
                    getline(cin, newNo);
                    user->updateMobileNo(oldNo, newNo);
                    db.save(atm.getUsers());
                    break;
                case 5:
                    cout << "Are you sure you want to delete your account? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (confirm == 'y' || confirm == 'Y')
                    {
                        db.deleteUser(accountNo);
                        cout << "Account deleted successfully.\n";
                        break;
                    }
                    break;
                case 6:
                    cout << "Logging out...\n";
                    return;
                default:
                    cout << "Invalid option. Try again.\n";
                }
            }
        }
        else if (initialChoice == 3)
        {
            cout << "Exiting ATM. Goodbye!\n";
            return;
        }
        else
        {
            cout << "Invalid selection. Please try again.\n";
        }
    }
}
