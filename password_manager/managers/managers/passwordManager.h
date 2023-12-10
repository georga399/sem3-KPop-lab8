#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

typedef unsigned long long ull;

extern "C" const char* passwordGenerator(ull);

#include <vector>
#include <string>
#include "dataManager.h"

class PasswordManager
{
private:
    inline static std::string username;
    DataManager dataManager;
public:
    PasswordManager(/* args */);
    bool Login(std::string username1, std::string pass);
    void Logout();
    std::vector<std::string> GetAllKeys();
    std::string GetPassword(std::string key);
    bool AddPassword(std::string key, std::string pass);
    bool DeletePassword(std::string key);
    std::string GenPassword(size_t size);
    ~PasswordManager();
};

#endif