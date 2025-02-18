// ATM.h - Header file for ATM class
#ifndef ATM_H
#define ATM_H

#include <vector>
#include "ATMUser.h"

class ATM
{
private:
    std::vector<ATMUser> users; // Stores a list of ATM users

public:
    // Adds a new user to the ATM system
    void addUser(const ATMUser &user);

    // Authenticates a user based on account number and PIN
    ATMUser *authenticateUser(long int accNo, int pin);

    // Returns the list of users (needed for JSON database operations)
    std::vector<ATMUser> &getUsers();
};

#endif // ATM_H