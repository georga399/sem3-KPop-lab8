#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "encryptManager.h"
#include <string>
#include <vector>

class DataManager
{
private:
    std::string path;
    EncryptManager encryptManager;
public:
    DataManager(std::string connectionString);
    bool Login(std::string & username, std::string & password);
    bool AddPassword(std::string username, std::string key, std::string password);
    std::string GetPassword(std::string username, std::string key);
    std::vector<std::string> GetAllUserKeys(std::string username);
    bool GenUser(std::string username, std::string password);
    bool DeletePassword(std::string username, std::string key);
};

#endif