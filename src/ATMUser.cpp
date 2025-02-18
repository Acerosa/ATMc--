// ATMUser.cpp - Implementation of ATMUser class
#include "header/ATMUser.h"

// Constructor: Initializes an ATM user with account details
ATMUser::ATMUser(long int accNo, string userName, int pin, double bal, string mobNo)
    : accountNo(accNo), name(userName), PIN(pin), balance(bal), mobileNo(mobNo) {}

// Returns the user's account number
long int ATMUser::getAccountNo() const { return accountNo; }

// Returns the user's name
string ATMUser::getName() const { return name; }

// Returns the user's PIN
int ATMUser::getPIN() const { return PIN; }

// Returns the user's balance
double ATMUser::getBalance() const { return balance; }

// Returns the user's mobile number
string ATMUser::getMobileNo() const { return mobileNo; }

// Updates the user's mobile number if the old one matches
void ATMUser::updateMobileNo(const string &oldNo, const string &newNo)
{
    if (oldNo == mobileNo)
    {
        mobileNo = newNo;
        cout << "Mobile number updated successfully.\n";
    }
    else
    {
        cout << "Incorrect old mobile number.\n";
    }
}

// Withdraws cash if sufficient balance is available
bool ATMUser::withdrawCash(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "Please collect your cash. Remaining Balance: " << balance << "\n";
        return true;
    }
    cout << "Invalid amount or insufficient funds.\n";
    return false;
}

// Deposits cash into the user's account
void ATMUser::depositCash(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Deposit successful. Updated Balance: " << balance << "\n";
    }
    else
    {
        cout << "Invalid deposit amount.\n";
    }
}