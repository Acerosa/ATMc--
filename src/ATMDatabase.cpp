// ATMDatabase.cpp - Implementation of ATMDatabase class
#include "header/ATMDatabase.h"

ATMDatabase::ATMDatabase(const std::string &dbFile) : filename(dbFile) {}

bool ATMDatabase::load(std::vector<ATMUser> &users)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Cannot open JSON database file. Creating a new one..." << std::endl;
        users.clear();
        save(users); // ✅ Create an empty database file if none exists
        return false;
    }

    json jsonData;
    file >> jsonData;
    file.close();

    users.clear();

    if (jsonData.contains("users") && jsonData["users"].is_array())
    {
        for (const auto &user : jsonData["users"])
        {
            users.emplace_back(
                user["accountNo"].get<long int>(),
                user["name"].get<std::string>(),
                user["PIN"].get<int>(),
                user["balance"].get<double>(),
                user["mobileNo"].get<std::string>());
        }
    }
    else
    {
        std::cerr << "Warning: JSON file is empty or has incorrect structure." << std::endl;
        return false;
    }

    return true;
}

bool ATMDatabase::save(const std::vector<ATMUser> &users)
{
    json jsonData;
    jsonData["users"] = json::array(); // Ensure it's an array

    for (const auto &user : users)
    {
        jsonData["users"].push_back({{"accountNo", user.getAccountNo()},
                                     {"name", user.getName()},
                                     {"PIN", user.getPIN()},
                                     {"balance", user.getBalance()},
                                     {"mobileNo", user.getMobileNo()}});
    }

    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Cannot write to JSON database file." << std::endl;
        return false;
    }

    file << jsonData.dump(4); // Pretty print JSON
    file.close();
    return true;
}

bool ATMDatabase::addUser(const ATMUser &user)
{
    std::vector<ATMUser> users;
    if (!load(users))
        return false; // ✅ Ensure load succeeds

    users.push_back(user); // ✅ Add new user to list
    return save(users);    // ✅ Save entire users list, not just `json` object
}

bool ATMDatabase::deleteUser(long int accountNo)
{
    std::vector<ATMUser> users;
    if (!load(users))
        return false; // ✅ Ensure users were loaded properly

    auto it = std::remove_if(users.begin(), users.end(),
                             [accountNo](const ATMUser &user)
                             { return user.getAccountNo() == accountNo; });

    if (it == users.end())
    {
        std::cerr << "Error: Account not found." << std::endl;
        return false; // ✅ Prevents saving an unchanged list
    }

    users.erase(it, users.end()); // ✅ Actually removes the user
    return save(users);           // ✅ Saves updated list
}