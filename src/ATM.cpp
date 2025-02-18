// ATM.cpp - Implementation of ATM class
#include "header/ATM.h"

// Adds a new user to the list
void ATM::addUser(const ATMUser &user)
{
    users.push_back(user);
}

// Authenticates a user based on account number and PIN
ATMUser *ATM::authenticateUser(long int accNo, int pin)
{
    for (auto &user : users)
    {
        if (user.getAccountNo() == accNo && user.getPIN() == pin)
        {
            return &user;
        }
    }
    return nullptr;
}

// Returns the list of users (reference)
std::vector<ATMUser> &ATM::getUsers()
{
    return users; // ✅ Ensure we return a reference
}