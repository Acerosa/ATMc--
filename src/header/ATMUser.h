// ATMUser.h - Header file for ATMUser class
#ifndef ATMUSER_H
#define ATMUSER_H

#include <iostream>
using namespace std;

class ATMUser
{
private:
    long int accountNo; // Stores the user's account number
    string name;        // Stores the user's name
    int PIN;            // Stores the user's PIN
    double balance;     // Stores the user's bank balance
    string mobileNo;    // Stores the user's mobile number

public:
    // Constructor: Initialize the user's account details
    ATMUser(long int accNo, string userName, int pin, double bal, string mobNo);

    // Getter methods: Retrieve user details
    long int getAccountNo() const;
    string getName() const;
    int getPIN() const;
    double getBalance() const;
    string getMobileNo() const;

    // Update the user's mobile number
    void updateMobileNo(const string &oldNo, const string &newNo);

    // Withdraw cash from the user's balance
    bool withdrawCash(double amount);

    // Deposit cash into the user's balance
    void depositCash(double amount);
};

#endif // ATMUSER_H