#ifndef ATMUSER_H
#define ATMUSER_H

#include <iostream>
using namespace std;

class ATMUser
{
private:
    // Stores the user's account number
    // Stores the user's name
    // Stores the user's PIN
    // Stores the user's bank balance
    // Stores the user's mobile number

public:
    ATMUser(long int accNo, string userName, int pin, double bal, string mobNo);

    // Getter methods: Retrieve user details

    // Update the user's mobile number
    void updateMobileNo(const string &oldNo, const string &newNo);
    // Withdraw cash from the user's balance
    bool withdrawCash(double amount);
};

#endif // ATMUSER_H