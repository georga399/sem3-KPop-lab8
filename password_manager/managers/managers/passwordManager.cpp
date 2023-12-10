#include "passwordManager.h"

PasswordManager::PasswordManager() : dataManager("../vault/")
{
}

PasswordManager::~PasswordManager()
{}

bool PasswordManager::Login(std::string username1, std::string pass)
{
     if(dataManager.Login(username1, pass))
     {
         PasswordManager::username = username1;
         return true;
     }
     return false;
}

std::vector<std::string> PasswordManager::GetAllKeys()
{
    return dataManager.GetAllUserKeys(PasswordManager::username);
}

std::string PasswordManager::GetPassword(std::string key)
{
    if(PasswordManager::username == "") return "";
    return dataManager.GetPassword(PasswordManager::username, key);
}

bool PasswordManager::AddPassword(std::string key, std::string pass)
{
    if(PasswordManager::username == "") return false;
    return dataManager.AddPassword(PasswordManager::username, key, pass);
}

bool PasswordManager::DeletePassword(std::string key)
{
    if(PasswordManager::username.empty()) return false;
    return dataManager.DeletePassword(PasswordManager::username, key);
}

std::string PasswordManager::GenPassword(size_t size)
{
    if(size < 2 || size > 100)
        return "";
    const char* passArr = passwordGenerator(size);
    auto passString = std::string(passArr);
    return passString;
}

void PasswordManager::Logout()
{
    username = "";
}
