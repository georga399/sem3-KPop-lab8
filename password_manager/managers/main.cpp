#include "managers/encryptManager.h"
#include "managers/dataManager.h"
#include "managers/passwordManager.h"
#include <iostream>
#include <string>

int main()
{   
    auto dataManager = DataManager("../vault/");
    // auto encryptManager = EncryptManager();
    // dataManager.GenUser("user", "changeme");
    // dataManager.AddPassword("user", "key1", "passKey1");
    // std::string pass = dataManager.GetPassword("user2", "key1");
    
    
    std::string username = "danik";
    std::string password = "loh";
    // auto lres = dataManager.Login(username, password);
    // std::cout << lres << std::endl;
    // std::cout << (lres == encryptManager.Encrypt(password)) << std::endl;
    auto passwordManager = PasswordManager();
    dataManager.GenUser(username, password);
    // if(passwordManager.Login(username, password))
    // {
    //     std::cout << "authorized" << std::endl;
    // }
    // else{
    //     std::cout << "bad credentials" << std::endl;
    // }
    // std::string key = "Randomkey";
    // std::string password2 = "passwordfish";
    // passwordManager.AddPassword(key, password2);
    // auto keys = passwordManager.GetAllKeys();
    // for (auto &&k : keys)
    // {
    //     std::cout << k << std::endl;
    // }
    // passwordManager.DeletePassword(key);
}