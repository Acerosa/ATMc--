#include "header/ATM.h"

void ATM::addUser(const ATMUser &user)
{
    users.push_back(user);
}

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