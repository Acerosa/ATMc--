#ifndef ATM_H
#define ATM_H

#include <vector>
#include "ATMUser.h"

class ATM
{
private:
    std::vector<ATMUser> users;

public:
    void addUser(const ATMUser &user);
    ATMUser *authenticateUser(long int accNo, int pin);
};

#endif // ATM_H