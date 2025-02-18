// ATMDatabase.h - Header file for ATMDatabase class
#ifndef ATMDATABASE_H
#define ATMDATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "ATMUser.h"
#include "json.hpp" // Include JSON library

using json = nlohmann::json;

class ATMDatabase
{
private:
    std::string filename; // JSON file that serves as the database
    json data;            // JSON object to store user data

public:
    ATMDatabase(const std::string &dbFile);       // Constructor to set database file
    bool load(std::vector<ATMUser> &users);       // Load users from JSON file
    bool save(const std::vector<ATMUser> &users); // Save users to JSON file
    bool addUser(const ATMUser &user);            // Add new user to JSON file
    bool deleteUser(long int accountNo);          // Delete a user from JSON file
};

#endif // ATMDATABASE_H
